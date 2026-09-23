cd "${0%/*}";
i686-linux-gnu-g++ GMAppImager.cpp GMAppImager-i686/libdlgmod.a GMAppImager-i686/libfilesystem.a GMAppImager-i686/libxprocess.a `pkg-config --cflags --libs x11 dbus-1` -I. -o GMAppImager-i686/GMAppImager;
