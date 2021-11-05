#! /bin/bash

# from https://pypi.org/project/fauxmo/
#python3 pip install --upgrade pip
#python3 -m pip install fauxmo

APPName=fauxmo
APPDIR="$HOME/$APPName"
APPSvcName="$APPName.service"

mkdir -p $APPDIR
cd $APPDIR

#wget https://raw.githubusercontent.com/n8henrie/fauxmo/master/extras/fauxmo.service
#wget https://raw.githubusercontent.com/n8henrie/fauxmo-plugins/master/mqttplugin.py

#fauxmo -c config.json

sudo useradd -r -s /bin/false fauxmo

sudo cp $APPDIR/$APPSvcName /etc/systemd/system
sudo chmod 755 /etc/systemd/system/$APPSvcName
sudo systemctl daemon-reload

sudo systemctl enable $APPSvcName
sudo systemctl start $APPSvcName

# kill remnants of fauxpi
#ps -fA | grep python

