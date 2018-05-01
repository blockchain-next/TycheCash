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

