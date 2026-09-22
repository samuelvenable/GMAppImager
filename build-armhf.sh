cd "${0%/*}";
g++ GMAppImager.cpp GMAppImager-armhf/libdlgmod.a GMAppImager-armhf/libfilesystem.a GMAppImager-armhf/libxprocess.a `pkg-config --cflags --libs x11 dbus-1` -I. -o GMAppImager-armhf/GMAppImager;
