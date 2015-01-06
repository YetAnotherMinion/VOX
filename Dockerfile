FROM phusion/baseimage:0.9.15
MAINTAINER yetanotherminion <yetanotherminion@gmail.com>
RUN echo "hello from server"

ENTRYPOINT["/bin/bash"]