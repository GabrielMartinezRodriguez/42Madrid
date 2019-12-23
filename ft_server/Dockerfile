FROM debian:buster

RUN  apt-get update && apt-get install -y mariadb-server wget nginx && \
     wget https://es.wordpress.org/wordpress-5.3.2-es_ES.tar.gz  && \
     tar -zxvf wordpress-5.3.2-es_ES.tar.gz 



EXPOSE 8080

COPY src/hola.txt /var

CMD [ "service", "nginx", "start" ]

