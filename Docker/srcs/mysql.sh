#!/bin/bash

 dpkg -i  mysql-apt-config_0.8.13-1_all.deb
 apt update
 apt install -y mysql-server
