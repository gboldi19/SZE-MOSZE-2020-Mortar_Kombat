FROM ubuntu:20.04
ENV TZ=Europe/Budapest
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install --no-install-recommends -y \
    cmake \
    make \
    doxygen \
    graphviz \
&& apt-get install -y git \
&& rm -rf /var/lib/apt/lists/*