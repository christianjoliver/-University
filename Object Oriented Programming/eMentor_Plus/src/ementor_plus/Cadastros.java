
package ementor_plus;

import java.awt.Toolkit;
import javax.swing.JOptionPane;

public class Cadastros extends javax.swing.JFrame {


    public Cadastros() {
        initComponents();
        Icone(); //Ícone do Form.
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Seletor = new javax.swing.JComboBox<>();
        LNome = new javax.swing.JLabel();
        T_Nome = new javax.swing.JTextField();
        LCPF = new javax.swing.JLabel();
        LData_Nascimento = new javax.swing.JLabel();
        LTelefone = new javax.swing.JLabel();
        LMatricula = new javax.swing.JLabel();
        T_Matricula = new javax.swing.JTextField();
        LPeriodo = new javax.swing.JLabel();
        LData_Admissao = new javax.swing.JLabel();
        LSalario_Bruto = new javax.swing.JLabel();
        BtnCadastrar = new javax.swing.JButton();
        T_Periodo = new javax.swing.JTextField();
        T_Data_Nascimento = new javax.swing.JFormattedTextField();
        T_Telefone = new javax.swing.JFormattedTextField();
        T_Data_Admissao = new javax.swing.JFormattedTextField();
        T_CPF = new javax.swing.JFormattedTextField();
        T_Salario_Bruto = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Formulário de Cadastro");
        setSize(new java.awt.Dimension(0, 0));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
        });

        Seletor.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Selecione uma Opção", "Aluno", "Professor" }));
        Seletor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SeletorActionPerformed(evt);
            }
        });

        LNome.setText("Nome:");

        T_Nome.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Nome.setPreferredSize(new java.awt.Dimension(46, 20));

        LCPF.setText("CPF:");

        LData_Nascimento.setText("Data de Nascimento:");

        LTelefone.setText("Telefone:");

        LMatricula.setText("Matrícula:");

        T_Matricula.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Matricula.setPreferredSize(new java.awt.Dimension(46, 20));

        LPeriodo.setText("Período:");

        LData_Admissao.setText("Data de Admissão:");

        LSalario_Bruto.setText("Salário Bruto:");

        BtnCadastrar.setText("CADASTRAR");
        BtnCadastrar.setPreferredSize(new java.awt.Dimension(117, 42));
        BtnCadastrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnCadastrarActionPerformed(evt);
            }
        });

        T_Periodo.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Periodo.setPreferredSize(new java.awt.Dimension(46, 20));

        try {
            T_Data_Nascimento.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("## / ## / ####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_Data_Nascimento.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_Data_Nascimento.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));

        try {
            T_Telefone.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("( ## )  #### - ####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_Telefone.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_Telefone.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Telefone.setPreferredSize(new java.awt.Dimension(46, 20));

        try {
            T_Data_Admissao.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("## / ## / ####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_Data_Admissao.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_Data_Admissao.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));

        try {
            T_CPF.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("###.###.###-##")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_CPF.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_CPF.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_CPF.setPreferredSize(new java.awt.Dimension(46, 20));

        T_Salario_Bruto.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Salario_Bruto.setPreferredSize(new java.awt.Dimension(46, 20));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Seletor, javax.swing.GroupLayout.PREFERRED_SIZE, 522, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(LNome, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(LMatricula, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(T_Matricula, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(T_Nome, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(LCPF, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(T_CPF, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(LPeriodo, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(T_Periodo, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(LData_Admissao, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(T_Data_Admissao, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(T_Data_Nascimento, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(LData_Nascimento)))
                            .addComponent(BtnCadastrar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(T_Telefone, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(LTelefone, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(LSalario_Bruto, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(T_Salario_Bruto, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(22, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(Seletor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(65, 65, 65)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(21, 21, 21)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(T_Nome, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(T_CPF, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(T_Data_Nascimento, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(T_Telefone, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(LData_Nascimento)
                            .addComponent(LCPF)
                            .addComponent(LTelefone)
                            .addComponent(LNome))
                        .addGap(48, 48, 48)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(LData_Admissao)
                            .addComponent(LPeriodo)
                            .addComponent(LMatricula)
                            .addComponent(LSalario_Bruto))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(T_Data_Admissao, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(T_Periodo, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(T_Matricula, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(T_Salario_Bruto, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 44, Short.MAX_VALUE)
                .addComponent(BtnCadastrar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void SeletorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SeletorActionPerformed
        
        /*Nenhum Item foi Selecionado.*/
        if(Seletor.getSelectedIndex() == 0){
            /*Habilita os campos únicos da Classe "Aluno".*/
            LMatricula.setVisible(true);
            T_Matricula.setVisible(true);   
            LPeriodo.setVisible(true);
            T_Periodo.setVisible(true);

            /*Habilita os campos únicos da Classe "Professsor".*/
            LData_Admissao.setVisible(true);
            T_Data_Admissao.setVisible(true);
            LSalario_Bruto.setVisible(true);
            T_Salario_Bruto.setVisible(true);
            
            /*Limpa os Campos Únicos de "Aluno" e "Professor".*/
            T_Matricula.setText("");
            T_Periodo.setText(""); 
            T_Data_Admissao.setText("");
            T_Salario_Bruto.setText(""); 
        }
        
        /*O Item Selecionado é "Aluno"*/
        if(Seletor.getSelectedIndex() == 1){
            /*Habilita os campos únicos da Classe "Aluno".*/
            LMatricula.setVisible(true);
            T_Matricula.setVisible(true);
            LPeriodo.setVisible(true);
            T_Periodo.setVisible(true);

            /*Desabilita os campos únicos da Classe "Professor".*/
            LData_Admissao.setVisible(false);
            T_Data_Admissao.setVisible(false);
            LSalario_Bruto.setVisible(false);
            T_Salario_Bruto.setVisible(false);
        }
        
        /*O Item Selecionado é "Professor"*/
        if(Seletor.getSelectedIndex() == 2){
            /*Desabilita os campos únicos da Classe "Aluno".*/
            LMatricula.setVisible(false);
            T_Matricula.setVisible(false);
            LPeriodo.setVisible(false);
            T_Periodo.setVisible(false);
            
            /*Habilita os campos únicos da Classe "Professor".*/
            LData_Admissao.setVisible(true);
            T_Data_Admissao.setVisible(true);
            LSalario_Bruto.setVisible(true);
            T_Salario_Bruto.setVisible(true);
        }       
    }//GEN-LAST:event_SeletorActionPerformed

    private void BtnCadastrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnCadastrarActionPerformed
        Conexoes_MySQL Conexao = new Conexoes_MySQL();
        
        if(Seletor.getSelectedIndex() == 0)
            JOptionPane.showMessageDialog(null, "Selecione uma Opção Válida!!!", "Informação", JOptionPane.INFORMATION_MESSAGE);
        
        /*Cadastro do Aluno.*/
        if(Seletor.getSelectedIndex() == 1){
            
            /*Verifica se há Campos Obrigatórios Vazios.*/
            if(T_Nome.getText().isEmpty() || T_CPF.getText().isEmpty() || T_Matricula.getText().isEmpty()|| T_Periodo.getText().isEmpty())
                JOptionPane.showMessageDialog(null, "Preencha os Campos Obrigatórios!!!", "Aviso", JOptionPane.WARNING_MESSAGE);
            else{
                Aluno Academico[] = new Aluno[100];
                Aluno Objeto_Aluno = new Aluno();
                
                /*Atribição de Dados do Objeto Aluno.*/
                Objeto_Aluno.Set_Dados(T_Nome.getText(), T_Data_Nascimento.getText(), T_CPF.getText(), T_Telefone.getText(), 
                                                Long.parseLong(T_Matricula.getText()), Integer.parseInt(T_Periodo.getText()));
                
                /*Atribição de Dados para a Base de Dados.*/
                Conexao.Insere_Dados_MySql(T_Nome.getText(), T_Data_Nascimento.getText(), T_CPF.getText(), T_Telefone.getText(), 
                                           Long.parseLong(T_Matricula.getText()), Integer.parseInt(T_Periodo.getText()), "", 0, 1);
                
                /*Limpa os Campos.*/
                T_Nome.setText("");
                T_CPF.setText("");
                T_Telefone.setText("");
                T_Data_Nascimento.setText("");
                T_Matricula.setText("");
                T_Periodo.setText("");                
            }
        }
        
        /*Cadastro do Professor.*/
        if(Seletor.getSelectedIndex() == 2){
            
            /*Verifica se há Campos Obrigatórios Vazios.*/
            if(T_Nome.getText().isEmpty() || T_CPF.getText().isEmpty() || T_Data_Admissao.getText().isEmpty() || T_Salario_Bruto.getText().isEmpty())
                JOptionPane.showMessageDialog(null, "Preencha os Campos Obrigatórios!!!", "Aviso", JOptionPane.WARNING_MESSAGE);
            else{
                Professor Professores[] = new Professor[100];
                Professor Objeto_Professor = new Professor();
                
                /*Atribição de Dados do Objeto Professor.*/
                Objeto_Professor.Set_Dados(T_Nome.getText(), T_Data_Nascimento.getText(), T_CPF.getText(), T_Telefone.getText(), 
                                                        T_Data_Admissao.getText(), Double.parseDouble(T_Salario_Bruto.getText()));
                
                /*Atribição de Dados para a Base de Dados.*/
                Conexao.Insere_Dados_MySql(T_Nome.getText(), T_Data_Nascimento.getText(), T_CPF.getText(), T_Telefone.getText(), 2, 1 ,
                                                        T_Data_Admissao.getText(), Double.parseDouble(T_Salario_Bruto.getText()), 2);
                
                /*Limpa os Campos.*/
                T_Nome.setText("");
                T_CPF.setText("");
                T_Telefone.setText("");
                T_Data_Nascimento.setText("");
                T_Data_Admissao.setText("");
                T_Salario_Bruto.setText("");                
            }
        }  
    }//GEN-LAST:event_BtnCadastrarActionPerformed

    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed
        /*Chama o Form "Menu" novamente.*/
        new Menu().show();
    }//GEN-LAST:event_formWindowClosed

    /**
     * @param args the command line arguments
     */
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
            java.util.logging.Logger.getLogger(Cadastros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Cadastros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Cadastros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Cadastros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Cadastros().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BtnCadastrar;
    private javax.swing.JLabel LCPF;
    private javax.swing.JLabel LData_Admissao;
    private javax.swing.JLabel LData_Nascimento;
    private javax.swing.JLabel LMatricula;
    private javax.swing.JLabel LNome;
    private javax.swing.JLabel LPeriodo;
    private javax.swing.JLabel LSalario_Bruto;
    private javax.swing.JLabel LTelefone;
    private javax.swing.JComboBox<String> Seletor;
    private javax.swing.JFormattedTextField T_CPF;
    private javax.swing.JFormattedTextField T_Data_Admissao;
    private javax.swing.JFormattedTextField T_Data_Nascimento;
    private javax.swing.JTextField T_Matricula;
    private javax.swing.JTextField T_Nome;
    private javax.swing.JTextField T_Periodo;
    private javax.swing.JTextField T_Salario_Bruto;
    private javax.swing.JFormattedTextField T_Telefone;
    // End of variables declaration//GEN-END:variables

    private void Icone() {
        setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("Icon.png")));
    }
}
