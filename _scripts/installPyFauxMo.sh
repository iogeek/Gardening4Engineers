#! /bin/bash

# from https://pypi.org/project/fauxmo/
python3 pip install --upgrade pip
python3 -m pip install fauxmo


Make a config.json based on config-sample.json
fauxmo -c config.json [-v]


mkdir -p $HOME/fauxmo
cd $HOME/fauxmo

wget https://raw.githubusercontent.com/n8henrie/fauxmo/master/extras/fauxmo.service
wget https://raw.githubusercontent.com/n8henrie/fauxmo-plugins/master/mqttplugin.py
