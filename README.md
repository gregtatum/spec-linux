# Linux Kernel Spec

This project is a test suite where I can encode my learnings with how the Linux kernel works. It requires Docker to run.

Ubuntu source:
https://kernel.ubuntu.com/git/ubuntu/ubuntu-bionic.git/tree/
`git clone git://kernel.ubuntu.com/ubuntu/ubuntu-bionic.git --depth 1`

Linux source:
https://github.com/torvalds/linux/tree/v4.9
`git clone git@github.com:torvalds/linux.git --depth 1`

## Building the docker image

Install Docker then run:

```
./build-docker.sh
```

## Compiling the test suite and running

```
./run.sh
```

## Run the image and use bash

```
./bash.sh
```
