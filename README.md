# mri_simulator
mri_simulator


## How to install QT5


## QT5 için Cmake

Şu (arkadaşın)[https://stackoverflow.com/questions/47471629/fail-to-use-q-object-macro-in-cmake-project`] yanıtı olmasa buralar gelemezdim.



install g++ 6.3.0 for matlab mex compiler for different mirrors [mirrors](https://gcc.gnu.org/mirrors.html)
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
