FROM ubuntu:20.04

RUN apt-get update && apt install --no-install-recommends -y \
    cmake \
    make \
    doxygen \
    graphviz \
&& rm -rf /var/lib/apt/lists/*