#! /bin/bash

# from https://pypi.org/project/fauxmo/
python3 pip install --upgrade pip
python3 -m pip install fauxmo


mkdir -p $HOME/fauxmo
cd $HOME/fauxmo

#wget https://raw.githubusercontent.com/n8henrie/fauxmo/master/extras/fauxmo.service
wget https://raw.githubusercontent.com/n8henrie/fauxmo-plugins/master/mqttplugin.py

fauxmo -c config.json

sudo useradd -r -s /bin/false fauxmo

sudo cp $HOME/fauxmo/fauxmo.service /etc/systemd/system/fauxmo.service

sudo systemctl enable fauxmo.service
sudo systemctl start fauxmo.service
