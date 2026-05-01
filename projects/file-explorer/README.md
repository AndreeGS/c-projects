# File Explorer CLI em C

Um explorador de arquivos via linha de comando, escrito em C, com arquitetura modular. Permite navegar por diretórios e manipular arquivos, com foco em conceitos de baixo nível e organização de código.

## Funcionalidades

- Listar arquivos e diretórios (`ls`)
- Navegar entre diretórios (`cd`)
- Remover arquivos (`rm`)
- Copiar arquivos (`cp`)
- Estrutura modular para fácil expansão

## Requisitos

- GCC (compilador C)  

No Ubuntu/Debian:

```bash
sudo apt install build-essential
```

## Como Compilar

```bash
make
```

## Como Executar

```bash
./file-explorer
```

## Limpar Arquivos Compilados

```bash
make
```

## Proximos passos/melhorias

- Adicionar listagem recursiva de diretórios
- Exibir permissões e tamanho dos arquivos
- Implementar busca por nome de arquivo
- Adicionar histórico de comandos
- Melhorar tratamento de erros
- Suporte a comandos mais avançados

### Feito como projeto pessoal para aprendizado em C, com foco em manipulação de sistema de arquivos e arquitetura de software.
