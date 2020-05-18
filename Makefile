.PHONY: all build upload clean program uploadfs update

all: build

# build project
build:
	platformio -c vim run -e cable

debug:
	platformio -c vim run -e cable --target debug

# build and upload (if no errors) using cable environment
upload:
	platformio -c vim run -e cable --target upload

# build and upload (if no errors) using over-the-air upload
uploadOTA:
	platformio -c vim run -e ota --target upload

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
