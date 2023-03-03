/* 
Quanto a Subclasse Professor, filha de Pessoa, deve possuir os atributos de 
Data de Admissão e Salário Bruto. Os métodos a serem implementados para essa 
subclasse são: Construtor padrão; construtor para inicializar todos os atributos; 
setDados para inicializar os atributos depois de criados os objetos; getDataAdmissao 
e getSalarioBruto para recuperar esses atributos; imprimir dados; e calcular salário 
líquido (de forma simplificada considerar desconto de 14% de INSS para todas as 
faixas de salário e 22,5% de IRPF para salários maiores ou iguais que R$ 5.000,00, 
os salários menores que o valor citado deve ter desconto apenas de INSS).
*/
package ementor_plus;

//implements Serializable
public class Professor extends Pessoa{
    private String Data_Admissao;
    private double Salario_Bruto;
    
    public Professor(){
        super();
        this.Data_Admissao = "";
        this.Salario_Bruto = 0.00;
    }

    public Professor(String Nome, String Data_Nascimento, String CPF, String Telefone,
    String Data_Admissao, double Salario_Bruto){
        super(Nome, Data_Nascimento, CPF, Telefone);
        this.Data_Admissao = Data_Admissao;
        this.Salario_Bruto = Salario_Bruto;
    }
    
    public void Set_Dados(String Nome, String Data_Nascimento, String CPF, String Telefone,
    String Data_Admissao, double Salario_Bruto){
        super.Set_Dados(Nome, Data_Nascimento, CPF, Telefone);
        this.Data_Admissao = Data_Admissao;
        this.Salario_Bruto = Salario_Bruto;
    }
    
    public void Set_Data_Admissao(String Data_Admissao){
        this.Data_Admissao = Data_Admissao;
    }

    public void Set_Salario_Bruto(double Salario_Bruto){
        this.Salario_Bruto = Salario_Bruto;
    }
    
    public String Get_Data_Admissao(){
        return this.Data_Admissao;
    }

    public double Get_Salario_Bruto(){
        return this.Salario_Bruto;
    }
    
    public void Imprimir_Dados(){
        System.out.println("Nome:               "+this.Nome 
                        +"\nCpf:                "+this.CPF
                        +"\nData Nascimento:    "+this.Data_Nascimento
                        +"\nData de Admissão:   "+this.Data_Admissao
                        +"\nSalário Bruto:      R$ "+this.Salario_Bruto);
    }
    
    public void Salario_Líquido(){
        double Desconto_INSS = this.Salario_Bruto * 0.14;
        double Desconto_IRPF = this.Salario_Bruto * 0.225;
        
        if(this.Salario_Bruto >= 5000)
            System.out.println("Salário Líquido:    R$ "+(this.Salario_Bruto 
                                                        -Desconto_INSS 
                                                        -Desconto_IRPF));
        else
            System.out.println("Salário Líquido:    R$ "+(this.Salario_Bruto 
                                                        -Desconto_INSS));
    }
}
