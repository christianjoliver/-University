
package ementor_plus;

import java.awt.Toolkit;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class Login extends javax.swing.JFrame {

    public Login() {
        initComponents();
        Icone(); //Ícone do Form.
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jOptionPane1 = new javax.swing.JOptionPane();
        LLogin = new javax.swing.JLabel();
        LSenha = new javax.swing.JLabel();
        T_Login = new javax.swing.JFormattedTextField();
        T_Senha = new javax.swing.JPasswordField();
        BtnEntrar = new javax.swing.JButton();
        Imagem = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Login");
        setMinimumSize(new java.awt.Dimension(400, 220));
        setType(java.awt.Window.Type.UTILITY);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });
        getContentPane().setLayout(null);

        LLogin.setText("Login:");
        getContentPane().add(LLogin);
        LLogin.setBounds(50, 43, 40, 16);

        LSenha.setText("Senha:");
        getContentPane().add(LSenha);
        LSenha.setBounds(50, 83, 39, 16);
        getContentPane().add(T_Login);
        T_Login.setBounds(108, 39, 227, 20);
        getContentPane().add(T_Senha);
        T_Senha.setBounds(108, 77, 227, 22);

        BtnEntrar.setText("Entrar");
        BtnEntrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnEntrarActionPerformed(evt);
            }
        });
        getContentPane().add(BtnEntrar);
        BtnEntrar.setBounds(136, 134, 106, 24);
        getContentPane().add(Imagem);
        Imagem.setBounds(-7, -3, 410, 190);

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnEntrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnEntrarActionPerformed
        Conexoes_MySQL Conexao = new Conexoes_MySQL();
        
        /*Verifica se há Campos Obrigatórios Vazios.*/
        if(T_Login.getText().isEmpty() || T_Senha.getText().isEmpty()){
            JOptionPane.showMessageDialog(null, "Preencha os Campos Obrigatórios!!!", "Aviso", JOptionPane.WARNING_MESSAGE);
        }else{
            String Log = T_Login.getText();
            String Senha = T_Senha.getText();
            Usuario User = Conexao.Verifica_Login(Log, Senha);
            
            /*Verifica se Login e Senha estão Corretos.*/
            if(User != null){
                /*Chama o Form "Menu" e fecha o Form "Login"*/
                Menu obj = new Menu();
                obj.setVisible(true);
                Login.this.dispose();
            }else{
                JOptionPane.showMessageDialog(null, "Usuário ou Senha Incorretos!!!", "Aviso", JOptionPane.WARNING_MESSAGE);
            }
        } 
    }//GEN-LAST:event_BtnEntrarActionPerformed

    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        //LLogin.setOpaque(true);
        //LLogin.setOpaque(true);
        //LSenha.setBackground(Color.gray);
        //LSenha.setBackground(Color.gray);
        
        /*Atribuí uma Imagem ao Tamanho definido do Label "Imagem".*/
        ImageIcon icone = new ImageIcon("src/ementor_plus/Imagem_Login.png");
        icone.setImage(icone.getImage().getScaledInstance(Imagem.getWidth(), Imagem.getHeight(), 1));
        Imagem.setIcon(icone);
    }//GEN-LAST:event_formWindowOpened

    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Login.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Login.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Login.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Login.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Login().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BtnEntrar;
    private javax.swing.JLabel Imagem;
    private javax.swing.JLabel LLogin;
    private javax.swing.JLabel LSenha;
    private javax.swing.JFormattedTextField T_Login;
    private javax.swing.JPasswordField T_Senha;
    private javax.swing.JOptionPane jOptionPane1;
    // End of variables declaration//GEN-END:variables

    private void Icone() {
        setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("Icon.png")));
    }
}
