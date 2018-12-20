# mri_simulator
mri_simulator

install g++ 6.3.0 for matlab mex compiler
```bash
 wget ftp://ftp.fu-berlin.de/unix/languages/gcc/releases/gcc-6.3.0/gcc-6.3.0.tar.gz
 tar xvf gcc-6.3.0.tar.gz
cd gcc-6.3.0
apt build-dep gcc
./contrib/download_prerequisites
cd ..
mkdir objdir
cd objdir
$PWD/../gcc-6.3.0/configure --prefix=/usr/bin/gcc-6.3 --enable-languages=c,c++,fortran,go --disable-multilib
make -j 8
make install

```
