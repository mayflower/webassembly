#!/bin/sh

wget http://www.ijg.org/files/jpegsrc.v8d.tar.gz .
tar xfz jpegsrc.v8d.tar.gz
cd jpeg-8d/

emconfigure ./configure
emmake make
