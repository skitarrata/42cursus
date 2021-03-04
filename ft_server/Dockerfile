# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 15:52:23 by svalenti          #+#    #+#              #
#    Updated: 2021/03/03 11:37:20 by svalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget

RUN apt-get -y install nginx
RUN rm -rf /etc/nginx/sites-available/default
COPY /srcs/nginx-config /etc/nginx/sites-available/default

RUN apt-get -y install mariadb-server

RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

WORKDIR /var/www/html
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

COPY /srcs/config.inc.php phpmyadmin/config.inc.php
COPY /srcs/wp-config.php wordpress/wp-config.php

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

WORKDIR ../../../
COPY /srcs/init-container.sh ./
COPY /srcs/autoindex_off.sh ./
COPY /srcs/autoindex_on.sh ./
CMD bash init-container.sh
