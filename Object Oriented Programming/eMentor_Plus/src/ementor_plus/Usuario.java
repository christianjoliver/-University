
package ementor_plus;

public class Usuario {
    private String Usuario;
    private String Senha;
    private String Nivel_Acesso;
    
    public Usuario(){
        this.Usuario = "";
        this.Senha = "";
        this.Nivel_Acesso = "";
    }
      
    public void Set_Dados(String NomeUsuario, String Senha, String NivelAcesso){
        this.Usuario = NomeUsuario;
        this.Senha = Senha;
        this.Nivel_Acesso = NivelAcesso;
    }
    
    public void Set_Usuario(String Usuario){
        this.Usuario = Usuario;
    }
    
    public void Set_Senha(String Senha){
        this.Senha = Senha;
    }
    
    public String Get_Usuario(){
        return this.Usuario;
    }
    
    public String Get_Senha(){
        return this.Senha;
    }
}
