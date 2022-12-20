#!/bin/sh -e

case $1 in
  playchain-tx)
    exec "$@"
    ;;

  playchain-cli)
    shift
    exec playchain-cli \
      --datadir="/var/lib/playchain" \
      --rpcconnect="${HOST}" \
      --rpcpassword="${RPC_PASSWORD}" \
      "$@"
    ;;

  playchaind)
    bin=$1
    shift
    ;;

  *)
    bin=playchaind
    ;;
esac

if [ -z "${RPC_PASSWORD}" ]
then
  echo "RPC_PASSWORD must be set"
  exit 1
fi

exec $bin \
  --datadir="/var/lib/playchain" \
  --rpcpassword="${RPC_PASSWORD}" \
  --rpcbind="${HOST}" \
  --rpcallowip="${RPC_ALLOW_IP}" \
  --zmqpubgameblocks="tcp://${HOST}:${ZMQ_PORT}" \
  --zmqpubgamepending="tcp://${HOST}:${ZMQ_PORT}" \
  "$@"
