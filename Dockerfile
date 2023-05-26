FROM ubuntu:latest

# Installation des dépendances nécessaires
RUN apt-get update && apt-get install -y \
    build-essential \
    libxext-dev \
    libx11-dev \
    xorg \
    libbsd-dev \
    && rm -rf /var/lib/apt/lists/*

# Copie de la bibliothèque miniLibX dans le conteneur
COPY mlx /usr/local/mlx

# Configuration des variables d'environnement
ENV DISPLAY=host.docker.internal:0

# Copie du code source dans le conteneur
COPY . /app

# Compilation du programme
WORKDIR /app
RUN make

# Déplacement de l'exécutable
RUN mv /app/src/so_long /app/so_long

# Commande d'exécution du programme
CMD ["/app/so_long"]
