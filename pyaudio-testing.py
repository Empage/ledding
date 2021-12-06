#!/usr/bin/python2
# Python 2.7 code to analyze sound and interface with Arduino

import pyaudio # from http://people.csail.mit.edu/hubert/pyaudio/
import serial  # from http://pyserial.sourceforge.net/
import numpy   # from http://numpy.scipy.org/
import audioop
import sys
import math
import struct
import json
import wave
import time
from datetime import datetime

'''
Sources

http://www.swharden.com/blog/2010-03-05-realtime-fft-graph-of-audio-wav-file-or-microphone-input-with-python-scipy-and-wckgraph/
http://macdevcenter.com/pub/a/python/2001/01/31/numerically.html?page=2

'''

def list_devices():
    # List all audio input devices
    p = pyaudio.PyAudio()
    i = 0
    n = p.get_device_count()
    while i < n:
        dev = p.get_device_info_by_index(i)
        if dev['maxInputChannels'] > 0:
            print str(i)+'. '+dev['name']
        i += 1

def arduino_soundlight():
    print "Starting Arduino Soundlight"
    chunk      = 2**11 # Change if too fast/slow, never less than 2**11
    scale      = 26    # Change if too dim/bright
    exponent   = 2.5     # Change if too little/too much difference between loud and quiet sounds
    samplerate = 44100

    # CHANGE THIS TO CORRECT INPUT DEVICE
    # Enable stereo mixing in your sound card
    # to make you sound output an input
    # Use list_devices() to list all your input devices
    device   = 0 # Original
    MAX = 0
    num_leds = 480 #Thats how my LEDs we have
    double = True
    print("Using Device: %s" % device)
    if double:
        num_leds = num_leds / 2# + 4
    else:
        num_leds = num_leds# + 4

    p = pyaudio.PyAudio()
    stream = p.open(format = pyaudio.paInt16,
                    channels = 1,
                    rate = 48000,
                    input = True,
                    frames_per_buffer = chunk,
                    input_device_index = device)

    print "Starting, use Ctrl+C to stop"
    try:
        ser = serial.Serial(
            port='/dev/serial0',
            baudrate = 115200,
            timeout = 5,
        )
        while True:
            data  = stream.read(chunk, exception_on_overflow = False)

            # Do FFT
            levels = calculate_levels(data, chunk, samplerate, num_leds)
            if double:
                new = list(reversed(levels)) + levels

            levels = new

            peak = abs(int(sum(levels)-(num_leds*2)))**3.0
            peak = int(peak / 100000 / 2.5)
            if peak > ( num_leds * 2 ) or peak > 254:
                peak = num_leds * 2

            # Make it look better and send to serial
            for index, level in enumerate(levels[2:]):
                level = int(level**4.0)

                if level >= 255:
                    level = 254
                elif level <= 60:
                    level = 0
                ser.write(chr(level))
            ser.write(chr(255))
            #TODO: For peak levels
            #ser.write(chr(int(peak)))
            s = ser.read()

    except KeyboardInterrupt:
        pass
    finally:
        print "\nStopping"
        stream.close()
        p.terminate()
        ser.close()

def calculate_levels(data, chunk, samplerate, num_leds):
    # Use FFT to calculate volume for each frequency
    global MAX

    # Convert raw sound data to Numpy array
    fmt = "%dH"%(len(data)/2)
    data2 = struct.unpack(fmt, data)
    data2 = numpy.array(data2, dtype='h')

    # Apply FFT
    fourier = numpy.fft.fft(data2)

    ffty = numpy.abs(fourier[0:len(fourier)/2])/1000
    ffty1=ffty[:len(ffty)/2]
    ffty2=ffty[len(ffty)/2::]+2
    ffty2=ffty2[::-1]
    ffty=ffty1+ffty2
    ffty=numpy.log(ffty)-2

    # we filter out the deep and high frequencies, because they are
    # a) not hearable
    # b) it looks so much better this way
    fourier = list(ffty)
    music_spectrum = len(fourier)/4
    fill_up = num_leds - len(fourier)/4
    fourier = fourier[:music_spectrum+fill_up]

    size = len(fourier)

    # Add up for num_leds lights
    levels = [int(abs(sum(fourier[i:(i+size/num_leds)]))) for i in xrange(0, size, size/num_leds)]

    return levels

if __name__ == '__main__':

    list_devices()
    arduino_soundlight()
