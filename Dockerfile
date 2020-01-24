FROM ubuntu:18.04
COPY . /usr/src/linux-app
WORKDIR /usr/src/linux-app

# Install things
RUN apt-get update \
    && apt-get install -y \
       build-essential \
    && apt-get autoclean -y \
    && rm -rf /var/lib/apt/lists/*

RUN gcc --version
