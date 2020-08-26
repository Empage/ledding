.PHONY: all build upload clean program uploadfs update

all: build

# build project in release configuration
build:
	PLATFORMIO_BUILD_FLAGS=`./set-environment.sh build_flags` \
	PLATFORMIO_UPLOAD_PORT=`./set-environment.sh cable_port` \
	platformio -c vim run

# build project in debug configuration
debug:
	PLATFORMIO_BUILD_FLAGS=`./set-environment.sh build_flags` \
	PLATFORMIO_UPLOAD_PORT=`./set-environment.sh cable_port` \
	platformio -c vim run -e debug

# build and upload (if no errors) using serial cable
upload:
	PLATFORMIO_BUILD_FLAGS=`./set-environment.sh build_flags` \
	PLATFORMIO_UPLOAD_PORT=`./set-environment.sh cable_port` \
	platformio -c vim run --target upload

# build and upload (if no errors) using over-the-air upload
ota:
	PLATFORMIO_BUILD_FLAGS=`./set-environment.sh build_flags` \
	PLATFORMIO_UPLOAD_PORT=`./set-environment.sh ota_port` \
	platformio -c vim run -e ota --target upload

# build, upload via JTAG and start debugger
debugJTAG:
	pio debug --interface gdb -x .pioinit

# clean compiled objects
clean:
	platformio  -c vim run --target clean

# update platforms and libraries via platformio (no target involvement)
update:
	platformio -c vim update

# only update dependend libraries
updateLibs:
	platformio lib update

# compile_commands.json e.g. for clangd autocompleter
compilecommands:
	platformio run -e ota --target compiledb && \
	mv .pio/build/ota/compile_commands.json .

# start serial console for ESP32 output
monitor:
	pio device monitor -b 115200

# target for my vim shortcut
tmp: build

# target for my vim shortcut
tmp2: uploadOTA

# upload using programmer
#program:
#	platformio -f -c vim run --target program

# upload files to filesystem SPIFFS
#uploadfs:
#	platformio -f -c vim run --target uploadfs

#updateCCLSfile:
	#platformio init --ide vim
