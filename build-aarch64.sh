cd "${0%/*}";
aarch64-linux-gnu-g++ GMAppImager.cpp GMAppImager-aarch64/libdlgmod.a GMAppImager-aarch64/libfilesystem.a GMAppImager-aarch64/libxprocess.a `pkg-config --cflags --libs x11 dbus-1` -I. -o GMAppImager-aarch64/GMAppImager;
