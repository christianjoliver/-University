
package ementor_plus;

import static com.sun.javafx.css.SizeUnits.EX;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Conexoes_MySQL {
    /*Seção de Variáveis Iniciais*/
    private String Drive_JDBC = "com.mysql.cj.jdbc.Driver"; /*Nome do Drive, dado pela Oracle.*/
    private String Caminho = "localhost"; /*Indica o server, localhost = na própia máquina.*/
    private String Porta = "3306"; /*Porta padrão de Conexão do MySql Server.*/
    private String Nome = "ementor"; /*Nome da Base de Dados.*/
    private String Usuario = "root"; /*Usuário padrão do MySql.*/
    private String Senha = "admin"; /*Senha definida na instalação do MySql.*/
    private String Fuso_Horario = "?useTimezone=true&serverTimezone=UTC";
    
    private String URL = "jdbc:mysql://" +Caminho +":" +Porta +"/" +Nome +Fuso_Horario;
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    
    /*Método para se Conectar a Base de Dados.*/
    public Connection Realiza_Conexao_MySql(){
        try{
            /*Estabelece a Conexão com o Drive (Via Conector_J).*/
            return DriverManager.getConnection(URL, Usuario, Senha);
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
            return null;
        }
    }
    
    /*Método para se Desconectar da Base de Dados.*/
    public void Realiza_Desconexao_MySql(Connection Conexao){
        try{
            if(Conexao != null) Conexao.close();
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    
    /*Método para Inserir dados nas Tabelas da Base de Dados.*/
    public void Insere_Dados_MySql(String Nome, String Data_Nascimento, String CPF, String Telefone, 
    long Matricula, int Periodo, String Data_Admissao, double Salario_Bruto, int Escolha){              
        Connection Conexao = Realiza_Conexao_MySql();
        String Sql_Pessoa = "INSERT INTO Pessoa(CPF, Nome, Telefone, Data_Nascimento) VALUES(?, ?, ?, ?)";
        String Sql_Aluno = "INSERT INTO Aluno(Matricula, CPF_Pessoa, Periodo) VALUES(?, ?, ?)";
        String Sql_Professor = "INSERT INTO Professor(CPF_Pessoa, Data_Admissao, Salario_Bruto) VALUES(?, ?, ?)";
         
        try{
            /*Cadastrando Dados na Tabela Pessoa.*/
            PreparedStatement Atuador_Pessoa = Conexao.prepareStatement(Sql_Pessoa);
            Atuador_Pessoa.setString(1, CPF);
            Atuador_Pessoa.setString(2, Nome);
            Atuador_Pessoa.setString(3, Telefone);
            Atuador_Pessoa.setString(4, Data_Nascimento);
            Atuador_Pessoa.execute();
            
            if(Escolha == 1){
                /*Cadastrando Dados na Tabela Aluno.*/
                PreparedStatement Atuador_Aluno = Conexao.prepareStatement(Sql_Aluno);
                Atuador_Aluno.setLong(1, Matricula);
                Atuador_Aluno.setString(2, CPF);
                Atuador_Aluno.setInt(3, Periodo);
                Atuador_Aluno.execute();
                
            }else if(Escolha == 2){
                /*Cadastrando Dados na Tabela Professor.*/
                PreparedStatement Atuador_Professor = Conexao.prepareStatement(Sql_Professor);
                Atuador_Professor.setString(1, CPF);
                Atuador_Professor.setString(2, Data_Admissao);
                Atuador_Professor.setDouble(3, Salario_Bruto);
                Atuador_Professor.execute();
            } 
            
            /*Mensagem de Cadastro Bem Sucedido.*/
            JOptionPane.showMessageDialog(null, "O Cadastro foi Efetuado com Sucesso!!!", "Cadastro", JOptionPane.INFORMATION_MESSAGE);
            /*Desconexão da Base de Dados.*/
            Realiza_Desconexao_MySql(Conexao);  
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE); 
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
     
    /*Método para Recuperar os Dados, da Base de Dados MySql, da Tabela "Aluno".*/
    public ArrayList<Aluno> Recupera_Dados_Aluno_MySql(String Tipo_Ordenacao){       
        Connection Conexao = Realiza_Conexao_MySql();
        ArrayList<Aluno> Academico = new ArrayList(); //Cria uma Lista do tipo Aluno.
        
        try{
            String Sql_Selecao_Aluno = "SELECT * FROM ementor.pessoa, ementor.aluno WHERE pessoa.CPF = aluno.CPF_Pessoa ORDER BY " +Tipo_Ordenacao +";";
            PreparedStatement Atuador_Selecao_Aluno = Conexao.prepareStatement(Sql_Selecao_Aluno);
            /*Resultado da Seleção do MySql.*/
            ResultSet Resultado_Selecao = Atuador_Selecao_Aluno.executeQuery();
            
            /*Seção para percorrer todas as Linhas resultantes da Seleção.*/
            while(Resultado_Selecao.next()){
                Aluno Objeto_Aluno = new Aluno();
                
                /*Seção para Inserir os Dados, da Base de Dados MySql, para o Objeto Aluno.*/
                Objeto_Aluno.CPF = Resultado_Selecao.getString("CPF");
                Objeto_Aluno.Nome = Resultado_Selecao.getString("Nome");
                Objeto_Aluno.Data_Nascimento = Resultado_Selecao.getString("Data_Nascimento");
                Objeto_Aluno.Telefone = Resultado_Selecao.getString("Telefone");
                Objeto_Aluno.Set_Matricula(Resultado_Selecao.getLong("Matricula"));
                Objeto_Aluno.Set_Periodo(Resultado_Selecao.getInt("Periodo"));
                
                /*Adiciona à Lista o Objeto_Aluno Atual.*/
                Academico.add(Objeto_Aluno);
            }
            Resultado_Selecao.close();
            Atuador_Selecao_Aluno.close();
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE); 
        }
        Realiza_Desconexao_MySql(Conexao);
        return Academico;
    }
    
    /*Método para Recuperar os Dados, da Base de Dados MySql, da Tabela "Aluno".*/
     public ArrayList<Professor> Recupera_Dados_Professor_MySql(String Tipo_Ordenacao){
        Connection Conexao = Realiza_Conexao_MySql();
        ArrayList<Professor> Professores = new ArrayList(); //Cria uma Lista do tipo Professor.
        
        try{
            String Sql_Selecao_Professor = "SELECT * FROM ementor.pessoa, ementor.professor WHERE pessoa.CPF = professor.CPF_Pessoa ORDER BY " +Tipo_Ordenacao +";";
            PreparedStatement Atuador_Selecao_Professor = Conexao.prepareStatement(Sql_Selecao_Professor);
            /*Resultado da Seleção do MySql.*/
            ResultSet Resultado_Selecao = Atuador_Selecao_Professor.executeQuery();
            
            /*Seção para percorrer todas as Linhas resultantes da Seleção.*/
            while(Resultado_Selecao.next()){
                Professor Objeto_Professor = new Professor();
                
                /*Seção para Inserir os Dados, da Base de Dados MySql, para o Objeto Professor.*/
                Objeto_Professor.CPF = Resultado_Selecao.getString("CPF");
                Objeto_Professor.Nome = Resultado_Selecao.getString("Nome");
                Objeto_Professor.Data_Nascimento = Resultado_Selecao.getString("Data_Nascimento");
                Objeto_Professor.Telefone = Resultado_Selecao.getString("Telefone");
                Objeto_Professor.Set_Data_Admissao(Resultado_Selecao.getString("Data_Admissao"));
                Objeto_Professor.Set_Salario_Bruto(Resultado_Selecao.getInt("Salario_Bruto"));
                
                /*Adiciona à Lista o Objeto_Professor Atual.*/
                Professores.add(Objeto_Professor);
            }      
            Resultado_Selecao.close();
            Atuador_Selecao_Professor.close();
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE); 
        } 
        Realiza_Desconexao_MySql(Conexao);
        return Professores;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////  
    
    /*Método para Buscar Dados de um Aluno na Base de Dados MySql.*/
    public Aluno Busca_Dados_Aluno(String CPF){
        Connection Conexao = Realiza_Conexao_MySql();
        Aluno Academico = new Aluno();
        Academico = null; //Marcador: Se não encontrou o CPF no MySQL permanece como null.
        
        try{
            String Sql_Selecao_Aluno = "SELECT *FROM ementor.pessoa, ementor.aluno WHERE pessoa.CPF = aluno.CPF_Pessoa and aluno.CPF_Pessoa ='" +CPF +"';";
            
            PreparedStatement Atuador_Selecao_Aluno  = Conexao.prepareStatement(Sql_Selecao_Aluno);
            ResultSet ResultadoSelecao = Atuador_Selecao_Aluno.executeQuery();
            
            /*Seção para percorrer todas as Linhas resultantes da Seleção
            (Talvez Desnecessário, uma vez que se procura diretamente pelo CPF).*/
            while(ResultadoSelecao.next()){
                Aluno Objeto_Aluno = new Aluno();
                
                /*Seção para Inserir os Dados, da Base de Dados MySql, para o Objeto Aluno.*/
                Objeto_Aluno.CPF = ResultadoSelecao.getString("CPF");
                Objeto_Aluno.Nome = ResultadoSelecao.getString("Nome");
                Objeto_Aluno.Data_Nascimento = ResultadoSelecao.getString("Data_Nascimento");
                Objeto_Aluno.Telefone = ResultadoSelecao.getString("Telefone");
                Objeto_Aluno.Set_Matricula(ResultadoSelecao.getLong("Matricula"));
                Objeto_Aluno.Set_Periodo(ResultadoSelecao.getInt("Periodo"));         
                
                Academico = Objeto_Aluno;
            }
            ResultadoSelecao.close();
            Atuador_Selecao_Aluno.close();
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
        }
        Realiza_Desconexao_MySql(Conexao); 
        return Academico;
    }
    
    /*Método para Buscar Dados de um Professor na Base de Dados MySql.*/
    public Professor Busca_Dados_Professor(String CPF){
        Connection Conexao = Realiza_Conexao_MySql();
        Professor Academico = new Professor();
        Academico = null; //Marcador: Se não encontrou o CPF no MySQL permanece como null.
        
        try{
            String Sql_Selecao_Aluno = "SELECT *FROM ementor.pessoa, ementor.professor WHERE pessoa.CPF = Professor.CPF_Pessoa and professor.CPF_Pessoa='" +CPF +"';";
            
            PreparedStatement Atuador_Selecao_Professor  = Conexao.prepareStatement(Sql_Selecao_Aluno);
            ResultSet ResultadoSelecao = Atuador_Selecao_Professor.executeQuery();
            
            /*Seção para percorrer todas as Linhas resultantes da Seleção
            (Talvez Desnecessário, uma vez que se procura diretamente pelo CPF).*/
            while(ResultadoSelecao.next()){
                Professor Objeto_Professor = new Professor();
                
                /*Seção para Inserir os Dados, da Base de Dados MySql, para o Objeto Professor.*/
                Objeto_Professor.CPF = ResultadoSelecao.getString("CPF");
                Objeto_Professor.Nome = ResultadoSelecao.getString("Nome");
                Objeto_Professor.Data_Nascimento = ResultadoSelecao.getString("Data_Nascimento");
                Objeto_Professor.Telefone = ResultadoSelecao.getString("Telefone");
                Objeto_Professor.Set_Data_Admissao(ResultadoSelecao.getString("Data_Admissao")); 
                Objeto_Professor.Set_Salario_Bruto(ResultadoSelecao.getDouble("Salario_Bruto"));         
                
                Academico = Objeto_Professor;
            }
            ResultadoSelecao.close();
            Atuador_Selecao_Professor.close();
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
        }
        Realiza_Desconexao_MySql(Conexao); 
        return Academico;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    
    /*Método para Atualizar dados de um Aluno na Base de Dados MySql.*/
    public void Atualiza_Dados_Aluno_MySQL(String Nome, String Data_Nascimento, String CPF, String Telefone, long Matricula, int Periodo){  
        Connection Conexao = Realiza_Conexao_MySql();     
        String Sql = "UPDATE ementor.pessoa, ementor.aluno SET Nome ='" +Nome +"', Data_Nascimento ='" +Data_Nascimento +"', " 
                   + "Telefone = '" +Telefone +"', Matricula =" +Matricula +", Periodo =" +Periodo                
                   + " WHERE pessoa.CPF = aluno.CPF_Pessoa AND aluno.CPF_Pessoa ='" +CPF +"';";        
        
        try{  
            PreparedStatement Atuador = Conexao.prepareStatement(Sql);
            Atuador.executeUpdate(); //Executa a Atulaização.
            Atuador.close();
            JOptionPane.showMessageDialog(null, "Dados Atualizados com Sucesso", "Salvar", JOptionPane.INFORMATION_MESSAGE);
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
        }
        Realiza_Desconexao_MySql(Conexao); 
    }
    
    /*Método para Atualizar dados de um Professor na Base de Dados MySql.*/
    public void Atualiza_Dados_Professor_MySQL(String Nome, String Data_Nascimento, String CPF, String Telefone, String Data_Admissao , Double Salario_Bruto){     
        Connection Conexao = Realiza_Conexao_MySql();   
        String Sql = "UPDATE ementor.pessoa, ementor.Professor SET Nome ='" +Nome +"', Data_Nascimento ='" +Data_Nascimento +"', "
                   + "Telefone ='" +Telefone +"', Data_Admissao ='" +Data_Admissao +"', Salario_Bruto =" +Salario_Bruto
                   + "WHERE pessoa.CPF = Professor.CPF_Pessoa and Professor.CPF_Pessoa ='" +CPF +"';";        
        
        try{
            PreparedStatement Atuador = Conexao.prepareStatement(Sql);
            Atuador.executeUpdate(); //Executa a Atulaização.
            Atuador.close();
            JOptionPane.showMessageDialog(null, "Dados Atualizados com Sucesso", "Salvar", JOptionPane.INFORMATION_MESSAGE);
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
        }
        Realiza_Desconexao_MySql(Conexao); 
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    
    public Usuario Verifica_Login(String Login, String Senha){
        Connection Conexao = Realiza_Conexao_MySql();
        Usuario User = new Usuario();
        User = null; //Marcador: Se não encontrou o Login e Senha no MySQL permanece como null.
        
        try{
            String Sql_Selecao_Usuario = "SELECT * FROM ementor.usuario WHERE usuario.user ='" +Login +"' and usuario.senha ='" +Senha +"';";
            //System.out.println(Sql_Selecao_Usuario);
            
            PreparedStatement Atuador_Selecao_Usuario  = Conexao.prepareStatement(Sql_Selecao_Usuario);
            ResultSet ResultadoSelecao = Atuador_Selecao_Usuario.executeQuery();
            
            /*Seção para percorrer todas as Linhas resultantes da Seleção
            (Talvez Desnecessário, uma vez que se procura diretamente pelo Login e Senha).*/
            while(ResultadoSelecao.next()){
                Usuario Objeto_Usuario = new Usuario();
                
                /*Seção para Inserir os Dados, da Base de Dados MySql, para o Objeto Usuario.*/
                Objeto_Usuario.Set_Usuario(ResultadoSelecao.getString("User"));
                Objeto_Usuario.Set_Senha(ResultadoSelecao.getString("Senha"));
            
                User = Objeto_Usuario;
            }
            ResultadoSelecao.close();
            Atuador_Selecao_Usuario.close();
            
        }catch(SQLException Ex){
            JOptionPane.showMessageDialog(null, "Algum Imprevisto Ocorreu:  " +Ex +"", "ERRO", JOptionPane.ERROR_MESSAGE);
        }
        Realiza_Desconexao_MySql(Conexao); 
        return User;
    }  
    
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
