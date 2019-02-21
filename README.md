## LyftIUL

<p align="center">
  <img src="others/intro.png" width="240"/>
</p>

### [Enunciado do projeto](others/enunciado.pdf)

### Introdução

O presente trabalho visa aplicar os conhecimentos adquiridos durante as aulas de Sistemas Operativos. O trabalho será composto de três partes, com o objectivo de desenvolver aspetos da plataforma LyftIUL. A Plataforma LyftIUL tem como objectivo ligar os estudantes do ISCTE-IUL que têm viatura própria (carro ou mota) com os estudantes que precisam de transporte para uma determinada viagem. Na plataforma LyftIUL existem os seguintes conceitos:

Condutor: é o estudante que faz o transporte. Um condutor tem um determinado perfil, que inclui a seguinte informação: número de estudante, nome, turma, número de telemóvel, email, tipo de viatura, marca, matrícula, número de viagens efetuadas, pontos e saldo atual.

Passageiro: é o estudante que precisa de se deslocar de uma determinada origem para um determinado destino. Um Passageiro tem um determinado perfil, que inclui a seguinte informação: número de estudante, nome, turma, número de telemóvel, e-mail, numero cartão de crédito.

Viatura: o meio de transporte utilizado pelo condutor para transportar o passageiro

Pedido: mensagem enviada pelo Passageiro a requisitar uma Viatura para o transportar naquele momento

Viagem: transporte de um Passageiro pelo Condutor num determinado período de tempo, com um determinado custo e com a qual foram obtidos pontos, utilizando uma Viatura.

Em termos gerais, quando um Passageiro precisa de transporte, utiliza o seu telemóvel para se ligar ao servidor tigre.iul.lab e requisitar um Condutor. Os condutores activos estão ligados ao servidor Tigre a aguardar pedidos.
