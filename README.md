# TycheCash
## Ubuntu 14.xx Install Guide

## Install Dependencies 
$`sudo apt-get install build-essential git cmake libboost1.55-all-dev` 

## Clone repository

$`git clone https://github.com/blockchain-next/TycheCash`

## Make TycheCash

$`cd TycheCash`

$`make or make -j (if parrlel processing is supported)`

## Running demon and mining

## 1st create a wallet
$`./simplewallet`

follow the instructions and note wallet address and remeber password

Run demon :

$`cd build/release/src`

$`./TycheCash`

on demon type:

`start_mining YOURWALLETADDRESS`

## Ubuntu 16.xx Install Guide

## Install Dependencies 
$`sudo apt install build-essential cmake pkg-config libboost-all-dev libssl-dev libunbound-dev libminiupnpc-dev libunwind8-dev liblzma-dev libldns-dev libexpat1-dev libgtest-dev doxygen graphviz` 

Though all of them are not necessary but in case of further updates it will be useful to have them all ready.
  ### Install gtest
  $`sudo apt-get install libgtest-dev && cd /usr/src/gtest && sudo cmake . && sudo make && sudo mv libg* /usr/lib/`
  
  $`cd`  
## Clone repository

$`git clone https://github.com/blockchain-next/TycheCash`

## Make TycheCash

$`cd TycheCash`

$`make or make -j (if parrlel processing is supported)`

## Running demon and mining

## 1st create a wallet
$`./simplewallet`

follow the instructions and note wallet address and remeber password

Run demon :

$`cd build/release/src`

$`./TycheCash`

on demon type:

`start_mining YOURWALLETADDRESS`

## MacOS Install Guide

## Install Dependencies 
Install Xcode 

  ### Install boost
  
  Get boost from : https://dl.bintray.com/boostorg/release/1.67.0/source/boost_1_67_0.tar.bz2
  
  Open Terminal
  
  $`cd Downloads`
  
  $`tar --bzip2 -xf boost_1_67_0.tar.bz2`
  
  $`cd boost_1_167_0`
  
  $`./bootstrap.sh --prefix=/usr/local/include`
  
  $`sudo ./b2 install`
  
  Enter your MacOS password when prompted
  
  $`cd`
  
  ### Install CMake 
  Download Cmake from : https://cmake.org/files/v3.11/cmake-3.11.1.tar.gz
  
  Install Cmake and copy CMake to Apllications 
  
  On terminal
  
  $` sudo "/Applications/CMake.app/Contents/bin/cmake-gui" --install`
  
## Clone repository

$`git clone https://github.com/blockchain-next/TycheCash`

## Make TycheCash

$`cd TycheCash`

$`make -j (if parrlel processing is supported)`

You can generate Xcode Xproject file to be opened and compiled in Xcode GUI by 
$`cmake -G xcode ..`

## Running demon and mining

## 1st create a wallet
$`./simplewallet`

follow the instructions and note wallet address and remeber password

Run demon :

$`cd build/release/src`

$`./TycheCash`

on demon type:

`start_mining YOURWALLETADDRESS`

## Windows Install Guide
