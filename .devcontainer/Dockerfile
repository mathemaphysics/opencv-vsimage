FROM ubuntu:18.04

# Set up the basic functionality
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update -y \
    && apt-get -y install libopencv-* \
    && apt-get -y install libopencv-dev \
    && apt-get -y install opencv-data opencv-doc
RUN apt-get install -y gdb language-pack-en-base
RUN apt-get install -y python3 python3-opencv
RUN apt-get install -y sqlite3
RUN apt-get install -y wget vim locate git

# Clone and build TileDB
WORKDIR /workspaces/tiledb
RUN git clone https://github.com/TileDB-Inc/TileDB
WORKDIR TileDB/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make && make install-tiledb
ENV LD_LIBRARY_PATH /usr/local/lib

# Clone and build PointCloudLibrary
WORKDIR /workspaces/pcl

# Instal proj from source
WORKDIR /workspaces/proj
RUN wget https://download.osgeo.org/proj/proj-6.3.1.tar.gz
RUN tar xvf proj-6.3.1.tar.gz
WORKDIR proj-6.3.1
RUN ./configure --prefix=/usr/local


# Download and build GDAL
WORKDIR /workspaces/gdal
RUN wget https://github.com/OSGeo/gdal/releases/download/v3.0.4/gdal-3.0.4.tar.gz
RUN tar xvf gdal-3.0.4.tar.gz
WORKDIR gdal-3.0.4


# Set the display to make life easier
ENV DISPLAY=172.50.1.221:0.0

ENTRYPOINT [ "/bin/bash" ]
