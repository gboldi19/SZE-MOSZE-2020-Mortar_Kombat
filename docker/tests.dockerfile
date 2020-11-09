FROM ubuntu:20.04

RUN apt-get update && apt install --no-install-recommends -y \
    gcc g++ \
    gcc-10 g++-10 \
    cmake \
    libgtest-dev \
    build-essential \
    valgrind \
    cppcheck \
&& rm -rf /var/lib/apt/lists/*