#!/bin/bash
if [ -f viagens.txt ]; then
	while IFS=":" read -r data condutor passageiro pontos saldo; do
		sed -i "s/$(cat condutores.txt | grep $condutor)/$(cat condutores.txt | grep $condutor | awk -F: -v pontos=$pontos -v saldototal=$(echo $(cat condutores.txt | grep $condutor | awk -F: '{print $11}') + $saldo | bc) '{print $1 ":" $2 ":" $3 ":" $4 ":" $5 ":" $6 ":" $7 ":" $8 ":" $9 + 1 ":" $10 + pontos ":" saldototal }')/" condutores.txt
	done <viagens.txt && rm -f viagens.txt
	echo "Condutores atualizado!"
else
	echo "Nada há viagens novas para atualizar."
fi
