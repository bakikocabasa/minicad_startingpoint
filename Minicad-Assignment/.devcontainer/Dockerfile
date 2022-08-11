FROM alpine:latest

RUN echo "  ---> Install packages" \
    && apk update \
    && apk upgrade \
    && apk --update add \
        bash \
        build-base \
        cmake \
        git \
        gdb \
        ncurses-dev \
        clang-extra-tools