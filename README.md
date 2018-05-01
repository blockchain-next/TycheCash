# TycheCash
## Ubuntu 14.xx Install Guide

## Install Dependencies 
$sudo apt-get install build-essential git cmake libboost1.55-all-dev 

Note : As of now only libboost1.55-all-dev works and so either work on Ubuntu 14.x or for higher versions make libboost1.55 for your system

## Clone repository

$git clone https://github.com/blockchain-next/TycheCash

## Make TycheCash

$cd TycheCash

$make or make -j (if parrlel processing is supported)

## Running demon and mining

## 1st create a wallet
$./simplewallet 

follow the instructions and note wallet address and remeber password

Run demon :

$cd build/release/src

$./TycheCash

on demon type:

start_mining YOURWALLETADDRESS
