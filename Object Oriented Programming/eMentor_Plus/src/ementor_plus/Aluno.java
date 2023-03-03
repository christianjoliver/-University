/*
A Subclasse Aluno, filha de Pessoa, deve conter os atributos de Matrícula 
e Período e os métodos: Construtor padrão; construtor para inicializar todos os 
atributos; setDados para inicializar todos os atributos após a criação dos objetos; 
getMatricula e getPeriodo para recuperar esses atributos; e outro método para 
imprimir os dados (preferencialmente utilizar mensagens gráficas de dialogo).
*/
package ementor_plus;

//implements Serilizable
public class Aluno extends Pessoa{
    private long Matricula;
    private int Periodo;
    
    public Aluno(){
        super();
        this.Matricula = 0;
        this.Periodo = 0;
    }

    public Aluno(String Nome, String Data_Nascimento, String CPF, String Telefone,
    long Matricula, int Periodo){
        super(Nome, Data_Nascimento, CPF, Telefone);
        this.Matricula = Matricula;
        this.Periodo = Periodo;
    }
    
    public void Set_Dados(String Nome, String Data_Nascimento, String CPF, String Telefone,
    long Matricula, int Periodo){
        super.Set_Dados(Nome, Data_Nascimento, CPF, Telefone);
        this.Matricula = Matricula;
        this.Periodo = Periodo;
    }
    
    public void Set_Matricula(long Matricula){
        this.Matricula = Matricula;
    }

    public void Set_Periodo(int Periodo){
        this.Periodo = Periodo;
    }
    
    public long Get_Matricula(){
        return this.Matricula;
    }

    public int Get_Periodo(){
        return this.Periodo;
    }
    
    public void Imprimir_Dados(){
        System.out.println("Nome:               "+this.Nome 
                        +"\nCpf:                "+this.CPF
                        +"\nData Nascimento:    "+this.Data_Nascimento
                        +"\nMatricula:          "+this.Matricula
                        +"\nPeriodo:            "+this.Periodo);
    }
}
