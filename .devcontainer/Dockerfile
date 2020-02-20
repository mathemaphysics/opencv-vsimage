FROM ubuntu:18.04

# Set up the basic functionality
ARG DEBIAN_FRONTEND=noninteractive

# Need to install tzdata first for time zones
RUN apt-get update -y \
	&& apt-get install -y tzdata

# Then make sure time zone is set to what it should be
RUN ln -fs /usr/share/zoneinfo/US/Central /etc/localtime \
	&& dpkg-reconfigure --frontend noninteractive tzdata

RUN apt-get update -y \
    && apt-get -y install libopencv-* \
    && apt-get -y install libopencv-dev \
    && apt-get -y install opencv-data opencv-doc
RUN apt-get install -y gdb language-pack-en-base
RUN apt-get install -y python3 python3-opencv
RUN apt-get install -y sqlite3 libkml-dev \
    && apt-get install -y --fix-missing libxml2 libxml2-dev \
    && apt-get install -y libhdf4-dev libhdf5-dev libnetcdf-dev \
    && apt-get install -y mongodb mongodb-dev libgeos-dev \
    && apt-get install -y libopenjp2-7-dev
RUN apt-get install -y wget vim locate git

# Clone and build TileDB
WORKDIR /workspaces/tiledb
RUN git clone https://github.com/TileDB-Inc/TileDB
WORKDIR TileDB/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make && make install-tiledb
ENV LD_LIBRARY_PATH /usr/local/lib

# Clone and build PointCloudLibrary
#WORKDIR /workspaces/pcl

# Instal proj from source
WORKDIR /workspaces/proj
RUN wget https://download.osgeo.org/proj/proj-6.3.1.tar.gz
RUN tar xvf proj-6.3.1.tar.gz
WORKDIR proj-6.3.1
RUN ./configure --prefix=/usr/local
RUN make && make install

# Download and build GDAL
WORKDIR /workspaces/gdal
RUN wget https://github.com/OSGeo/gdal/releases/download/v3.0.4/gdal-3.0.4.tar.gz
RUN tar xvf gdal-3.0.4.tar.gz
WORKDIR gdal-3.0.4
RUN ./configure --prefix=/usr/local --with-proj=/usr/local
RUN make && make install

# Download and build GeographicLib
WORKDIR /workspaces/geographiclib
RUN wget https://sourceforge.net/projects/geographiclib/files/distrib/GeographicLib-1.50.1.tar.gz
RUN tar xvf GeographicLib-1.50.1.tar.gz
WORKDIR GeographicLib-1.50.1
RUN ./configure --prefix=/usr/local
RUN make && make install

# Set the display to make life easier
ENV DISPLAY=172.50.1.221:0.0

ENTRYPOINT [ "/bin/bash" ]
