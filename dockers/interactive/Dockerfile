FROM ubuntu:15.04


RUN dpkg-divert --local --rename --add /sbin/initctl && rm -f /sbin/initctl && ln -s /bin/true /sbin/initctl

ENV TERM dumb

RUN apt-get update && apt-get -y install php5-cli php5-common php5-ldap

CMD ["/usr/bin/php", "-a"]
