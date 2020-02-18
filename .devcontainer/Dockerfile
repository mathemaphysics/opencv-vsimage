FROM ubuntu:18.04

# Set up the basic functionality
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update -y \
    && apt-get -y install libopencv-* \
    && apt-get -y install libopencv-dev \
    && apt-get -y install opencv-data opencv-doc
RUN apt-get install -y gdb language-pack-en-base
RUN apt-get install -y python3 python3-opencv
RUN apt-get install -y locate
RUN apt-get install -y git

# Clone and build TileDB
WORKDIR /workspaces/tiledb
RUN git clone https://github.com/TileDB-Inc/TileDB
WORKDIR TileDB/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make && make install-tiledb
ENV LD_LIBRARY_PATH /usr/local/lib

# Set the display to make life easier
ENV DISPLAY=172.50.1.221:0.0

ENTRYPOINT [ "/bin/bash" ]
