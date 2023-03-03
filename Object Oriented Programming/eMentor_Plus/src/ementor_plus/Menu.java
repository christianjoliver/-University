
package ementor_plus;

import java.awt.Toolkit;
import javax.swing.ImageIcon;

public class Menu extends javax.swing.JFrame {

    public Menu() {
        initComponents();
        Icone(); //Ícone do Form.
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        BtnCadastrar = new javax.swing.JButton();
        BtnListar = new javax.swing.JButton();
        BtnAlterar_Dados = new javax.swing.JButton();
        BtnSair = new javax.swing.JButton();
        Imagem = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        BtnCadastrar.setText("Cadastrar");
        BtnCadastrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnCadastrarActionPerformed(evt);
            }
        });

        BtnListar.setText("Listar");
        BtnListar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnListarActionPerformed(evt);
            }
        });

        BtnAlterar_Dados.setText("Alterar Dados");
        BtnAlterar_Dados.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnAlterar_DadosActionPerformed(evt);
            }
        });

        BtnSair.setText("Sair");
        BtnSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnSairActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(Imagem, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addGap(33, 33, 33)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(BtnAlterar_Dados, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(BtnCadastrar, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(BtnListar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(BtnSair, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(46, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(Imagem, javax.swing.GroupLayout.DEFAULT_SIZE, 175, Short.MAX_VALUE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BtnCadastrar)
                    .addComponent(BtnListar))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BtnAlterar_Dados)
                    .addComponent(BtnSair))
                .addGap(25, 25, 25))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void BtnCadastrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnCadastrarActionPerformed
        Cadastros Interface_Cadastro = new Cadastros();
        Interface_Cadastro.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_BtnCadastrarActionPerformed

    private void BtnListarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnListarActionPerformed
        Listagem Interface_Listagem = new Listagem();
        Interface_Listagem.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_BtnListarActionPerformed

    private void BtnAlterar_DadosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnAlterar_DadosActionPerformed
        Alterar_Dados Interface_Altera_Dados = new Alterar_Dados();
        Interface_Altera_Dados.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_BtnAlterar_DadosActionPerformed

    private void BtnSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnSairActionPerformed
        /*Saída do Programa.*/
        System.exit(0);
    }//GEN-LAST:event_BtnSairActionPerformed

    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        /*Atribuí uma Imagem ao Tamanho definido do Label "Imagem".*/
        ImageIcon icone = new ImageIcon("src/ementor_plus/Logo_UFES.png");
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
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Menu().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BtnAlterar_Dados;
    private javax.swing.JButton BtnCadastrar;
    private javax.swing.JButton BtnListar;
    private javax.swing.JButton BtnSair;
    private javax.swing.JLabel Imagem;
    // End of variables declaration//GEN-END:variables

    private void Icone() {
        setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("Icon.png")));
    }
}
