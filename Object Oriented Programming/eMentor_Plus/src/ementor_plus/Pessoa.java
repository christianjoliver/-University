/*
A Classe mãe Pessoa deve possuir os atributos de Nome, Data de Nascimento, CPF 
e Telefone. Em relação aos métodos, deve ser implementado o método construtor 
padrão e método construtor para inicializar todos os atributos.
*/
package ementor_plus;

import java.io.Serializable;

public class Pessoa implements Serializable{
    protected String Nome;
    protected String Data_Nascimento;
    protected String CPF;
    protected String Telefone;
    
    public Pessoa(){
        this.Nome = "";
        this.Data_Nascimento = "";
        this.CPF = "";
        this.Telefone = "";
    }

    public Pessoa(String Nome, String Data_Nascimento, String CPF, String Telefone){
        this.Nome = Nome;
        this.Data_Nascimento = Data_Nascimento;
        this.CPF = CPF;
        this.Telefone = Telefone;
    }
    
    public void Set_Dados(String Nome, String Data_Nascimento, String CPF, String Telefone){
        this.Nome = Nome;
        this.Data_Nascimento = Data_Nascimento;
        this.CPF = CPF;
        this.Telefone = Telefone;
    }
}
