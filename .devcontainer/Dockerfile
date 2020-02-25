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
    && apt-get install -y libxml2 libxml2-dev \
    && apt-get install -y libhdf4-dev libhdf5-dev libnetcdf-dev \
    && apt-get install -y mongodb mongodb-dev libgeos-dev \
    && apt-get install -y libopenjp2-7-dev
RUN apt-get install -y wget vim locate git

# Make sure libraries installed can be found in the future
ENV LD_LIBRARY_PATH /usr/local/lib
ENV LIBRARY_PATH=/usr/local/lib

# Clone and build TileDB
WORKDIR /workspaces/tiledb
RUN git clone https://github.com/TileDB-Inc/TileDB
WORKDIR TileDB/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make && make install-tiledb

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

## Adding liblas and PDAL's needed libgdal-dev installs
## another version of proj, which interferes with compilation
## of GDAL against proj-6; install them afterward
#RUN apt-get install -y libgdal-dev liblas-bin liblas-c-dev \
#    && apt-get install -y liblas-c3 liblas-dev liblas3

# Clone and build PDAL
RUN apt-get install -y libgeotiff2 libgeotiff-dev
WORKDIR /workspaces/pdal
RUN git clone https://github.com/PDAL/PDAL.git
WORKDIR PDAL/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make && make install

# Clone and build PCL
RUN apt-get install -y libeigen3-dev libflann-dev libqhull-dev libusb-1.0 libusb-dev vtk7 libvtk7-dev libboost-all-dev
WORKDIR /workspaces/pcl
RUN git clone https://github.com/PointCloudLibrary/pcl.git
WORKDIR pcl/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
RUN make
RUN make install

# Clone and build LASTools
WORKDIR /workspaces/lastools
RUN git clone https://github.com/LAStools/LAStools.git
WORKDIR LAStools/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
RUN make
RUN make install

# Install some python modules
RUN apt-get install -y python3-pip
RUN pip3 install meshio pyhull pyproj shapely pandas geopandas matplotlib
RUN apt-get install -y cookiecutter

# Start from here
WORKDIR /workspaces/opencv

# Set the display to make life easier
ENV DISPLAY=172.50.1.221:0.0

ENTRYPOINT [ "/bin/bash" ]
