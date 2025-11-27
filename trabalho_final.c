#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================================
// ESTRUTURAS
// ================================

typedef struct aluno {
    char nome[100];
    char endereco[200];
    char telefone[20];
    int idade;
    struct aluno *prox;
} Aluno;

typedef struct curso {
    char codigo[20];
    char nome[100];
    char instrutor[100];
    struct curso *prox;
} Curso;

typedef struct matricula {
    int numero;
    Aluno *aluno;
    Curso *curso;
    struct matricula *prox;
} Matricula;

// ================================
// LISTAS
// ================================
Aluno *listaAlunos = NULL;
Curso *listaCursos = NULL;
Matricula *listaMatriculas = NULL;

// Variável global para gerar número sequencial de matrícula
int numeroMatriculaGlobal = 1;

// ================================
// FUNÇÃO DE ERRO
// ================================
static void reportar_erro(char *mensagem) {
    printf("ERRO: %s\n", mensagem);
}

// ================================
// FUNÇÕES DE BUSCA
// ================================
Aluno *buscarAluno(char *nome) {
    Aluno *p = listaAlunos;
    while (p) {
        if (strcmp(p->nome, nome) == 0) return p;
        p = p->prox;
    }
    return NULL;
}

Curso *buscarCurso(char *codigo) {
    Curso *p = listaCursos;
    while (p) {
        if (strcmp(p->codigo, codigo) == 0) return p;
        p = p->prox;
    }
    return NULL;
}

Matricula *buscarMatricula(int numero) {
    Matricula *p = listaMatriculas;
    while (p) {
        if (p->numero == numero) return p;
        p = p->prox;
    }
    return NULL;
}

// Conta alunos de um curso
int contarAlunosCurso(Curso *curso) {
    int count = 0;
    Matricula *m = listaMatriculas;
    while (m) {
        if (strcmp(m->curso->codigo, curso->codigo) == 0)
            count++;
        m = m->prox;
    }
    return count;
}

// Verifica se aluno já está matriculado no curso
int alunoJaMatriculado(Aluno *a, Curso *c) {
    Matricula *m = listaMatriculas;
    while (m) {
        if (m->aluno == a && m->curso == c) return 1;
        m = m->prox;
    }
    return 0;
}

// ================================
// OPERAÇÕES COM ALUNOS
// ================================
void cadastrarAluno() {
    char nome[100];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    if (buscarAluno(nome)) {
        reportar_erro("Aluno já existe.");
        return;
    }

    Aluno *a = malloc(sizeof(Aluno));
    strcpy(a->nome, nome);
    printf("Endereco: ");
    scanf(" %[^\n]", a->endereco);
    printf("Telefone: ");
    scanf(" %[^\n]", a->telefone);
    printf("Idade: ");
    scanf("%d", &a->idade);

    a->prox = listaAlunos;
    listaAlunos = a;

    printf("Aluno cadastrado com sucesso!\n");
}

void atualizarAluno() {
    char nome[100];
    printf("Nome do aluno a atualizar: ");
    scanf(" %[^\n]", nome);

    Aluno *a = buscarAluno(nome);
    if (!a) {
        reportar_erro("Aluno nao encontrado.");
        return;
    }

    printf("Novo endereco: ");
    scanf(" %[^\n]", a->endereco);
    printf("Novo telefone: ");
    scanf(" %[^\n]", a->telefone);
    printf("Nova idade: ");
    scanf("%d", &a->idade);

    printf("Aluno atualizado!\n");
}

void procurarAluno() {
    char nome[100];
    printf("Nome do aluno: ");
    scanf(" %[^\n]", nome);

    Aluno *a = buscarAluno(nome);
    if (!a) {
        reportar_erro("Aluno nao encontrado.");
        return;
    }

    printf("Aluno encontrado:\n");
    printf("Nome: %s\nEndereco: %s\nTelefone: %s\nIdade: %d\n",
        a->nome, a->endereco, a->telefone, a->idade);
}

void descadastrarAluno() {
    char nome[100];
    printf("Nome do aluno: ");
    scanf(" %[^\n]", nome);

    Aluno *anterior = NULL, *p = listaAlunos;
    while (p) {
        if (strcmp(p->nome, nome) == 0) {
            if (anterior) anterior->prox = p->prox;
            else listaAlunos = p->prox;

            // remove matrículas
            Matricula *m = listaMatriculas, *antm = NULL;
            while (m) {
                if (m->aluno == p) {
                    if (antm) antm->prox = m->prox;
                    else listaMatriculas = m->prox;
                    free(m);
                    m = (antm ? antm->prox : listaMatriculas);
                } else {
                    antm = m;
                    m = m->prox;
                }
            }

            free(p);
            printf("Aluno removido.\n");
            return;
        }
        anterior = p;
        p = p->prox;
    }

    reportar_erro("Aluno nao encontrado.");
}

// ================================
// OPERAÇÕES COM CURSOS
// ================================
void cadastrarCurso() {
    char codigo[20];
    printf("Codigo: ");
    scanf(" %[^\n]", codigo);

    if (buscarCurso(codigo)) {
        reportar_erro("Curso ja existe.");
        return;
    }

    Curso *c = malloc(sizeof(Curso));
    strcpy(c->codigo, codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c->nome);
    printf("Instrutor: ");
    scanf(" %[^\n]", c->instrutor);

    c->prox = listaCursos;
    listaCursos = c;

    printf("Curso cadastrado!\n");
}

void procurarCurso() {
    char codigo[20];
    printf("Codigo do curso: ");
    scanf(" %[^\n]", codigo);

    Curso *c = buscarCurso(codigo);
    if (!c) {
        reportar_erro("Curso nao encontrado.");
        return;
    }

    printf("Curso encontrado:\n");
    printf("Codigo: %s\nNome: %s\nInstrutor: %s\n", c->codigo, c->nome, c->instrutor);
}

void atualizarCurso() {
    char codigo[20];
    printf("Codigo do curso: ");
    scanf(" %[^\n]", codigo);

    Curso *c = buscarCurso(codigo);
    if (!c) {
        reportar_erro("Curso nao encontrado.");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", c->nome);
    printf("Novo instrutor: ");
    scanf(" %[^\n]", c->instrutor);

    printf("Curso atualizado!\n");
}

void descadastrarCurso() {
    char codigo[20];
    printf("Codigo: ");
    scanf(" %[^\n]", codigo);

    Curso *anterior = NULL, *p = listaCursos;
    while (p) {
        if (strcmp(p->codigo, codigo) == 0) {
            if (anterior) anterior->prox = p->prox;
            else listaCursos = p->prox;

            // remove matrículas
            Matricula *m = listaMatriculas, *antm = NULL;
            while (m) {
                if (m->curso == p) {
                    if (antm) antm->prox = m->prox;
                    else listaMatriculas = m->prox;
                    free(m);
                    m = (antm ? antm->prox : listaMatriculas);
                } else {
                    antm = m;
                    m = m->prox;
                }
            }

            free(p);
            printf("Curso removido.\n");
            return;
        }
        anterior = p;
        p = p->prox;
    }

    reportar_erro("Curso nao encontrado.");
}

// ================================
// MATRÍCULAS
// ================================
void matricularAluno() {
    char nome[100], codigo[20];

    printf("Nome do aluno: ");
    scanf(" %[^\n]", nome);
    Aluno *a = buscarAluno(nome);

    if (!a) {
        reportar_erro("Aluno inexistente.");
        return;
    }

    printf("Codigo do curso (ou deixe vazio para matricular automaticamente): ");
    fgets(codigo, sizeof(codigo), stdin); // limpar buffer
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    Curso *c = NULL;

    if (strlen(codigo) > 0) {
        c = buscarCurso(codigo);
        if (!c) {
            reportar_erro("Curso inexistente.");
            return;
        }
    } else {
        // matricular automaticamente no curso com menos alunos
        Curso *p = listaCursos;
        int menor = 999999;
        while (p) {
            int x = contarAlunosCurso(p);
            if (x < menor) {
                menor = x;
                c = p;
            }
            p = p->prox;
        }
        if (!c) {
            reportar_erro("Nao ha cursos cadastrados.");
            return;
        }
    }

    if (alunoJaMatriculado(a, c)) {
        reportar_erro("Aluno ja matriculado neste curso.");
        return;
    }

    Matricula *m = malloc(sizeof(Matricula));
    m->aluno = a;
    m->curso = c;
    m->numero = numeroMatriculaGlobal++;
    m->prox = listaMatriculas;
    listaMatriculas = m;

    printf("Matriculado! Numero da matricula: %d\n", m->numero);
}

void procurarMatricula() {
    int num;
    printf("Numero da matricula: ");
    scanf("%d", &num);

    Matricula *m = buscarMatricula(num);
    if (!m) {
        reportar_erro("Matricula nao encontrada.");
        return;
    }

    printf("Matricula encontrada:\n");
    printf("Numero: %d\nAluno: %s\nCurso: %s (%s)\n",
           m->numero, m->aluno->nome, m->curso->nome, m->curso->codigo);
}

void cancelarMatricula() {
    int num;
    printf("Numero da matricula: ");
    scanf("%d", &num);

    Matricula *anterior = NULL, *p = listaMatriculas;
    while (p) {
        if (p->numero == num) {
            if (anterior) anterior->prox = p->prox;
            else listaMatriculas = p->prox;
            free(p);
            printf("Matricula cancelada.\n");
            return;
        }
        anterior = p;
        p = p->prox;
    }

    reportar_erro("Matricula nao encontrada.");
}

// ================================
// LISTAGENS
// ================================
void listarMatriculas() {
    Matricula *m = listaMatriculas;
    while (m) {
        printf("%d - %s -> %s\n", m->numero, m->aluno->nome, m->curso->nome);
        m = m->prox;
    }
}

void listarCursos() {
    Curso *c = listaCursos;
    while (c) {
        printf("%s - %s (%s)\n", c->codigo, c->nome, c->instrutor);
        c = c->prox;
    }
}

void listarAlunos() {
    Aluno *a = listaAlunos;
    while (a) {
        printf("%s - %s - %s - %d\n", a->nome, a->endereco, a->telefone, a->idade);
        a = a->prox;
    }
}

void listarAlunosCurso() {
    char codigo[20];
    printf("Codigo do curso: ");
    scanf(" %[^\n]", codigo);

    Curso *c = buscarCurso(codigo);
    if (!c) {
        reportar_erro("Curso nao encontrado.");
        return;
    }

    Matricula *m = listaMatriculas;
    while (m) {
        if (m->curso == c)
            printf("%s\n", m->aluno->nome);
        m = m->prox;
    }
}

void listarCursosAluno() {
    char nome[100];
    printf("Nome do aluno: ");
    scanf(" %[^\n]", nome);

    Aluno *a = buscarAluno(nome);
    if (!a) {
        reportar_erro("Aluno nao encontrado.");
        return;
    }

    Matricula *m = listaMatriculas;
    while (m) {
        if (m->aluno == a)
            printf("%s\n", m->curso->nome);
        m = m->prox;
    }
}

void listarAlunosSemCurso() {
    Aluno *a = listaAlunos;
    while (a) {
        int tem = 0;
        Matricula *m = listaMatriculas;
        while (m) {
            if (m->aluno == a) { tem = 1; break; }
            m = m->prox;
        }
        if (!tem) printf("%s\n", a->nome);
        a = a->prox;
    }
}

void listarCursosSemAlunos() {
    Curso *c = listaCursos;
    while (c) {
        int tem = 0;
        Matricula *m = listaMatriculas;
        while (m) {
            if (m->curso == c) { tem = 1; break; }
            m = m->prox;
        }
        if (!tem) printf("%s\n", c->nome);
        c = c->prox;
    }
}

// ================================
// SALVAR E CARREGAR ARQUIVOS
// ================================
void salvarDados() {
    FILE *fa = fopen("alunos.bin", "wb");
    FILE *fc = fopen("cursos.bin", "wb");
    FILE *fm = fopen("matriculas.bin", "wb");

    // salvar alunos
    Aluno *a = listaAlunos;
    while (a) {
        fwrite(a, sizeof(Aluno), 1, fa);
        a = a->prox;
    }

    // salvar cursos
    Curso *c = listaCursos;
    while (c) {
        fwrite(c, sizeof(Curso), 1, fc);
        c = c->prox;
    }

    // salvar matrículas
    Matricula *m = listaMatriculas;
    while (m) {
        fwrite(&m->numero, sizeof(int), 1, fm);
        fwrite(m->aluno->nome, sizeof(char), 100, fm);
        fwrite(m->curso->codigo, sizeof(char), 20, fm);
        m = m->prox;
    }

    fwrite(&numeroMatriculaGlobal, sizeof(int), 1, fm);

    fclose(fa);
    fclose(fc);
    fclose(fm);

    printf("Dados salvos.\n");
}

void carregarDados() {
    FILE *fa = fopen("alunos.bin", "rb");
    FILE *fc = fopen("cursos.bin", "rb");
    FILE *fm = fopen("matriculas.bin", "rb");

    if (!fa || !fc || !fm) {
        printf("Nenhum dado carregado (arquivos inexistentes).\n");
        return;
    }

    // carregar alunos
    Aluno tempA;
    while (fread(&tempA, sizeof(Aluno), 1, fa)) {
        Aluno *a = malloc(sizeof(Aluno));
        *a = tempA;
        a->prox = listaAlunos;
        listaAlunos = a;
    }

    // carregar cursos
    Curso tempC;
    while (fread(&tempC, sizeof(Curso), 1, fc)) {
        Curso *c = malloc(sizeof(Curso));
        *c = tempC;
        c->prox = listaCursos;
        listaCursos = c;
    }

    // carregar matrículas
    int num;
    char nome[100], codigo[20];

    while (fread(&num, sizeof(int), 1, fm)) {
        if (!fread(nome, sizeof(char), 100, fm)) break;
        if (!fread(codigo, sizeof(char), 20, fm)) break;

        Aluno *a = buscarAluno(nome);
        Curso *c = buscarCurso(codigo);
        if (a && c) {
            Matricula *m = malloc(sizeof(Matricula));
            m->numero = num;
            m->aluno = a;
            m->curso = c;
            m->prox = listaMatriculas;
            listaMatriculas = m;
        }
    }

    fread(&numeroMatriculaGlobal, sizeof(int), 1, fm);

    fclose(fa);
    fclose(fc);
    fclose(fm);

    printf("Dados carregados.\n");
}

// ================================
// MENU
// ================================
void menu() {
    printf("\n===== SISTEMA DE CURSOS =====\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Procurar aluno\n");
    printf("3 - Atualizar aluno\n");
    printf("4 - Descadastrar aluno\n");
    printf("5 - Cadastrar curso\n");
    printf("6 - Procurar curso\n");
    printf("7 - Atualizar curso\n");
    printf("8 - Descadastrar curso\n");
    printf("9 - Matricular aluno\n");
    printf("10 - Procurar matricula\n");
    printf("11 - Cancelar matricula\n");
    printf("12 - Listar todas as matriculas\n");
    printf("13 - Listar todos os cursos\n");
    printf("14 - Listar todos os alunos\n");
    printf("15 - Listar todos os alunos de um curso\n");
    printf("16 - Listar todos os alunos de todos os cursos\n");
    printf("17 - Listar todos os cursos de um aluno\n");
    printf("18 - Listar todos os cursos de todos os alunos\n");
    printf("19 - Listar todas as matriculas de um aluno\n");
    printf("20 - Listar todas as matriculas de um curso\n");
    printf("21 - Listar alunos sem curso\n");
    printf("22 - Listar cursos sem alunos\n");
    printf("23 - Sair\n");
    printf("Opcao: ");
}

// ================================
// MAIN
// ================================
int main() {
    carregarDados();

    int op;
    do {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1: cadastrarAluno(); break;
            case 2: procurarAluno(); break;
            case 3: atualizarAluno(); break;
            case 4: descadastrarAluno(); break;
            case 5: cadastrarCurso(); break;
            case 6: procurarCurso(); break;
            case 7: atualizarCurso(); break;
            case 8: descadastrarCurso(); break;
            case 9: matricularAluno(); break;
            case 10: procurarMatricula(); break;
            case 11: cancelarMatricula(); break;
            case 12: listarMatriculas(); break;
            case 13: listarCursos(); break;
            case 14: listarAlunos(); break;
            case 15: listarAlunosCurso(); break;
            case 21: listarAlunosSemCurso(); break;
            case 22: listarCursosSemAlunos(); break;
            case 23: salvarDados(); printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (op != 23);

    return 0;
}