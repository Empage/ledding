#!/usr/bin/python
# import alsaaudio
# print(alsaaudio.cards())


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


# /usr/share/sounds/alsa/Front_Center.wav


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
    chunk      = 2**12 # Change if too fast/slow, never less than 2**11
    scale      = 26    # Change if too dim/bright
    exponent   = 1     # Change if too little/too much difference between loud and quiet sounds
    samplerate = 44100

    # CHANGE THIS TO CORRECT INPUT DEVICE
    # Enable stereo mixing in your sound card
    # to make you sound output an input
    # Use list_devices() to list all your input devices
    device   = 2 # Original
    MAX = 0
    num_leds = 140
    double = True
    if double:
        num_leds = num_leds / 2 + 4
    else:
        num_leds = num_leds + 4

    p = pyaudio.PyAudio()
    stream = p.open(format = pyaudio.paInt16,
                    channels = 2,
                    rate = 44100,
                    # rate = 192000,
                    input = True,
                    frames_per_buffer = chunk,
                    input_device_index = device)

    print "Starting, use Ctrl+C to stop"
    try:
        ser = serial.Serial(
            port='/dev/ttyAMA0',
            # port='/dev/ttyUSB0',
            # baudrate = 115200, # That might be 2 fast
            baudrate = 115200,
        )
        while True:
            data  = stream.read(chunk, exception_on_overflow = False)

            '''
            # Old RMS code, will only show the volume

            rms   = audioop.rms(data, 2)

            level = min(rms / (2.0 ** 16) * scale, 1.0)
            level = level**exponent
            level = int(level * 255)

            print level
            ser.write(chr(level))
            '''

            # Do FFT
            levels = calculate_levels(data, chunk, samplerate, num_leds)
            # print levels
            if double:
                new = list(reversed(levels)) + levels


            levels = new
            print levels
            # Make it look better and send to serial
            for index, level in enumerate(levels):
                # level = int(level**1.5)
                level = max(min(level / scale, 1.0), 0.0)
                level = level**exponent
                level = int(level * 255)
                if level >= 255:
                    level = 254
                elif level <= 60:
                    level = 0
                # print level
                # print("{}: {}".format(index, level))
                ser.write(chr(level))
            ser.write(chr(255))
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
    # numpy.set_printoptions(threshold=sys.maxint) # prints the whole list
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

    fourier = list(ffty)[4:-4]
    fourier = fourier[:len(fourier)/2]

    size = len(fourier)

    # Add up for num_leds lights
    levels = [int(abs(sum(fourier[i:(i+size/num_leds)]))) for i in xrange(0, size, size/num_leds)][2:-2] # backup
    # levels = [int(sum(fourier[i:(i+size/num_leds)])) for i in xrange(0, size, size/num_leds)][:num_leds]

    return levels

if __name__ == '__main__':

    #list_devices()
    arduino_soundlight()