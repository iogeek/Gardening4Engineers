 sudo apt -y update
 sudo apt -y upgrade

# install dotnet.  Based on https://github.com/dotnet/install-scripts
wget https://dot.net/v1/dotnet-install.sh
#./dotnet-install.sh  -Channel Current -DryRun
./dotnet-install.sh  -Channel Current
rm dotnet-install.sh 


ln -s $HOME/.dotnet/dotnet /usr/local/bin 
echo ‘export DOTNET_ROOT=$HOME/.dotnet’ >> $HOME/.bashrc dotnet –info
#

 sudo apt-get install -y build-essential dos2unix git python3 ruby-full
 
 # jekyll
 gem update
 gem install jekyll bundler minima
 #

