.PHONY: all build upload clean program uploaffs update

all: build

# build project
# -f: --force, accept any confirmation prompts
build:
	platformio -f -c vim run

debug:
	platformio -f -c vim run --target debug

# build and upload (if no errors)
upload:
	platformio -f -c vim run --target upload

# clean compiled objects
clean:
	platformio -f -c vim run --target clean

# upload using programmer
program:
	platformio -f -c vim run --target program

# upload files to filesystem SPIFFS
uploadfs:
	platformio -f -c vim run --target uploadfs

# update platforms and libraries via platformio (no target involvement)
update:
	platformio -f -c vim update
