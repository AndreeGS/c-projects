# Password Manager em C

Um gerenciador de senhas simples, escrito em C, com arquitetura modular e criptografia básica usando OpenSSL. Permite salvar, listar e proteger credenciais de serviços de forma segura.

## Estrutura do projeto
password-manager/
│
├── crypto/ # Funções de criptografia e hashing
├── models/ # Estruturas de dados (Credential, Vault)
├── storage/ # Leitura e gravação do vault em disco
├── vault/ # Lógica do gerenciador (CRUD)
├── main.c # Interface principal (CLI)
└── Makefile # Arquivo de compilação

## Funcionalidades

- Adicionar credenciais (serviço, usuário e senha)
- Listar credenciais salvas
- Criptografar e descriptografar o arquivo do vault
- Estrutura modular para fácil expansão

## Requisitos

- GCC (compilador C)
- OpenSSL (`-lcrypto`)  

No Ubuntu/Debian:

```bash
sudo apt install build-essential libssl-dev
```

# Como Compilar

```bash
make
```

# Como Executar

```bash
./password_manager
```

# Limpar Arquivos Compilados

```bash
make clean
```

# Próximos passos / melhorias
- Adicionar remoção de credenciais
- Implementar senha mestra com hashing seguro e salt
- Limpeza de memória sensível
- Menu interativo mais completo
- Geração de senhas seguras automaticamente


### Feito como projeto pessoal para aprendizado em C e segurança de dados.