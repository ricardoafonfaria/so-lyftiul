#!/bin/bash
if [ "$(cat condutores.txt | awk -F: '{if(int(($10/$9)+0.5) < 5) print $0}')" ]; then
	read -p "Deseja enviar e-mail aos condutores na lista negra?" sy
	case $sy in
	[SsYy]* ) cat condutores.txt | awk -F: '{if(int(($10/$9)+0.5) < 5) print $0}' | while IFS=":" read -r numero nome turma telemovel email tipo marca matricula viagens pontos saldo; do
		echo "Caro(a) $nome o seu saldo é $saldo€, mas o seu rating não é o melhor, como tal está em risco de ser excluído da plataforma!" | mail -s "LiftIUL - Aviso!" $email
		done ;;
	* ) echo "Não foi enviado nenhum email."
	esac
else 
	echo "Não existe nenhum condutor na lista negra!"
fi
