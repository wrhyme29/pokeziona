FROM ubuntu:24.04
USER root
RUN \
  apt update && \
  apt upgrade -y && \
  apt install -y \
    git \
    libpng16-16 \
    python3 \
    wget
RUN --mount=target=/tmp/install-devkitpro-pacman,source=mount/install-devkitpro-pacman \
  /tmp/install-devkitpro-pacman && \
  ln -s /proc/self/mounts /etc/mtab && \
  dkp-pacman -Sy && \
  dkp-pacman -S --noconfirm gba-dev
WORKDIR /workspace
RUN \
  git config --global --add safe.directory /workspace
ENTRYPOINT ["/bin/sh", "-l", "-c"]
CMD ["/bin/bash"]
