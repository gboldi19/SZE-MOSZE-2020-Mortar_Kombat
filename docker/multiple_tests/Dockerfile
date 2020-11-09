FROM ubuntu:20.04
ENV TZ=Europe/Budapest
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt install --no-install-recommends -y \
    gcc g++ \
    gcc-10 g++-10 \
    cmake \
    libgtest-dev \
    build-essential \
    valgrind \
    cppcheck \
&& rm -rf /var/lib/apt/lists/*