
package ementor_plus;

import java.awt.Toolkit;
import javax.swing.JOptionPane;

public class Alterar_Dados extends javax.swing.JFrame {

    public Alterar_Dados() {
        initComponents();
        Icone(); //Ícone do Form.
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        LData_Admissao = new javax.swing.JLabel();
        LSalario_Bruto = new javax.swing.JLabel();
        Seletor = new javax.swing.JComboBox<>();
        LNome = new javax.swing.JLabel();
        T_Periodo = new javax.swing.JTextField();
        T_Nome = new javax.swing.JTextField();
        T_Data_Nascimento = new javax.swing.JFormattedTextField();
        LCPF = new javax.swing.JLabel();
        T_Telefone = new javax.swing.JFormattedTextField();
        LData_Nascimento = new javax.swing.JLabel();
        T_Data_Admissao = new javax.swing.JFormattedTextField();
        LTelefone = new javax.swing.JLabel();
        T_CPF = new javax.swing.JFormattedTextField();
        LMatricula = new javax.swing.JLabel();
        T_Salario_Bruto = new javax.swing.JTextField();
        T_Matricula = new javax.swing.JTextField();
        LPeriodo = new javax.swing.JLabel();
        BtnBuscar = new javax.swing.JButton();
        BtnCancelar = new javax.swing.JButton();
        BtnSalvar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        LData_Admissao.setText("Data de Admissão:");

        LSalario_Bruto.setText("Salário Bruto:");

        Seletor.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Selecione uma Opção", "Aluno", "Professor" }));
        Seletor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SeletorActionPerformed(evt);
            }
        });

        LNome.setText("Nome:");

        T_Periodo.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Periodo.setPreferredSize(new java.awt.Dimension(46, 20));

        T_Nome.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Nome.setPreferredSize(new java.awt.Dimension(46, 20));

        try {
            T_Data_Nascimento.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("## / ## / ####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_Data_Nascimento.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_Data_Nascimento.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));

        LCPF.setText("Digite o CPF:");

        try {
            T_Telefone.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("( ## )  #### - ####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_Telefone.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_Telefone.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Telefone.setPreferredSize(new java.awt.Dimension(46, 20));

        LData_Nascimento.setText("Data de Nascimento:");

        try {
            T_Data_Admissao.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("## / ## / ####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_Data_Admissao.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_Data_Admissao.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));

        LTelefone.setText("Telefone:");

        try {
            T_CPF.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("###.###.###-##")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        T_CPF.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        T_CPF.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_CPF.setPreferredSize(new java.awt.Dimension(46, 20));

        LMatricula.setText("Matrícula:");

        T_Salario_Bruto.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Salario_Bruto.setPreferredSize(new java.awt.Dimension(46, 20));

        T_Matricula.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        T_Matricula.setPreferredSize(new java.awt.Dimension(46, 20));

        LPeriodo.setText("Período:");

        BtnBuscar.setText("Buscar");
        BtnBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnBuscarActionPerformed(evt);
            }
        });

        BtnCancelar.setText("Cancelar");
        BtnCancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnCancelarActionPerformed(evt);
            }
        });

        BtnSalvar.setText("Salvar");
        BtnSalvar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtnSalvarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(Seletor, javax.swing.GroupLayout.PREFERRED_SIZE, 522, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(BtnBuscar, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(BtnSalvar, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(153, 153, 153)
                        .addComponent(BtnCancelar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                        .addComponent(LMatricula, javax.swing.GroupLayout.DEFAULT_SIZE, 117, Short.MAX_VALUE)
                                        .addComponent(T_Matricula, javax.swing.GroupLayout.DEFAULT_SIZE, 117, Short.MAX_VALUE))
                                    .addGap(18, 18, 18)
                                    .addComponent(LPeriodo, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGroup(layout.createSequentialGroup()
                                    .addGap(135, 135, 135)
                                    .addComponent(T_Periodo, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addComponent(T_Nome, javax.swing.GroupLayout.PREFERRED_SIZE, 252, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(LNome, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(LData_Admissao, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(T_Data_Admissao))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(T_Salario_Bruto, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(LSalario_Bruto, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(T_Data_Nascimento)
                                    .addComponent(LData_Nascimento, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(T_Telefone, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(LTelefone, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addComponent(LCPF, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 117, Short.MAX_VALUE)
                        .addComponent(T_CPF, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addComponent(Seletor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 77, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(21, 21, 21)
                        .addComponent(T_CPF, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(LCPF))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(21, 21, 21)
                                .addComponent(T_Nome, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(LNome))
                        .addGap(2, 2, 2))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                            .addGap(21, 21, 21)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(T_Data_Nascimento, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(T_Telefone, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(LData_Nascimento)
                            .addComponent(LTelefone))))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(LPeriodo)
                            .addComponent(LMatricula))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(T_Periodo, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(T_Matricula, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                        .addGroup(layout.createSequentialGroup()
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(LData_Admissao)
                                .addComponent(LSalario_Bruto))
                            .addGap(30, 30, 30))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(T_Data_Admissao, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(T_Salario_Bruto, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(48, 48, 48)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BtnSalvar)
                    .addComponent(BtnCancelar)
                    .addComponent(BtnBuscar))
                .addGap(33, 33, 33))
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

    private void BtnBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnBuscarActionPerformed
        Conexoes_MySQL Conexao = new Conexoes_MySQL();
        
        /*Verifica se o Campo Obrigatório "CPF" está vazio.*/
        if(T_CPF.getText().isEmpty())
            JOptionPane.showMessageDialog(null, "Preencha o campo CPF!!!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        
        else if(Seletor.getSelectedIndex()==0){
            JOptionPane.showMessageDialog(null, "Selecione uma opção válida!!!", "Alerta", JOptionPane.INFORMATION_MESSAGE);   
        }
        
        else if(Seletor.getSelectedIndex()==1){
            /*Busca os dados do Aluno e coloca nos TextEdit.*/
            Aluno Aluno_Encontrado = Conexao.Busca_Dados_Aluno(T_CPF.getText());

            if(Aluno_Encontrado!=null){
                BtnSalvar.setEnabled(true);
                Seletor.setEnabled(false);
                T_CPF.setEnabled(false);
                BtnBuscar.setEnabled(false);
                T_Nome.setText(Aluno_Encontrado.Nome);
                T_Data_Nascimento.setText(Aluno_Encontrado.Data_Nascimento);
                T_Telefone.setText(Aluno_Encontrado.Telefone);
                T_Matricula.setText(Long.toString(Aluno_Encontrado.Get_Matricula()));
                T_Periodo.setText(Integer.toString(Aluno_Encontrado.Get_Periodo()));
            }
            else{
                JOptionPane.showMessageDialog(null, "Registro não Encontrado", "Busca", JOptionPane.INFORMATION_MESSAGE);
                T_Nome.setText("");
                T_Periodo.setText("");
                T_CPF.setText("");
                T_Data_Nascimento.setText("");
                T_Telefone.setText("");
                T_Matricula.setText("");
            }
        }
        else if(Seletor.getSelectedIndex()==2){
            /*Busca os dados do Professor e coloca nos TextEdit.*/
            Professor Professor_Encontrado = Conexao.Busca_Dados_Professor(T_CPF.getText());
            
            if(Professor_Encontrado!=null){
                BtnSalvar.setEnabled(true);
                Seletor.setEnabled(false);
                T_CPF.setEnabled(false);
                BtnBuscar.setEnabled(false);
                T_Nome.setText(Professor_Encontrado.Nome);
                T_Data_Nascimento.setText(Professor_Encontrado.Data_Nascimento);            
                T_Telefone.setText(Professor_Encontrado.Telefone);
                T_Data_Admissao.setText(Professor_Encontrado.Get_Data_Admissao());
                T_Salario_Bruto.setText(Double.toString(Professor_Encontrado.Get_Salario_Bruto()));
            }
            else{
                JOptionPane.showMessageDialog(null, "Registro não Encontrado", "Busca", JOptionPane.INFORMATION_MESSAGE);
                T_Nome.setText("");
                T_Data_Nascimento.setText("");
                T_CPF.setText("");
                T_Telefone.setText("");
                T_Data_Admissao.setText("");
                T_Salario_Bruto.setText("");
            }
        }
    }//GEN-LAST:event_BtnBuscarActionPerformed

    private void BtnSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnSalvarActionPerformed
        Conexoes_MySQL Conexao = new Conexoes_MySQL();
        
        /*Verifica se há Campos Obrigatórios Vazios.*/
        if(T_Nome.getText().isEmpty() || T_CPF.getText().isEmpty() || T_Telefone.getText().isEmpty() || T_Data_Nascimento.getText().isEmpty()){
            JOptionPane.showMessageDialog(null, "Preencha todos os campos!!!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
        }
        
        else if(Seletor.getSelectedIndex()==1 && T_Matricula.getText().isEmpty()==false && T_Periodo.getText().isEmpty()==false){
            /*Atualiza os Dados na tabela "Aluno".*/
            Conexao.Atualiza_Dados_Aluno_MySQL(T_Nome.getText(), T_Data_Nascimento.getText(), T_CPF.getText(), T_Telefone.getText(),
                                                        Long.parseLong(T_Matricula.getText()), Integer.parseInt(T_Periodo.getText()));
            /*Limpa os Campos.*/
            BtnCancelar.doClick();
        }
        else if(Seletor.getSelectedIndex()==2 && T_Salario_Bruto.getText().isEmpty()==false && T_Data_Admissao.getText().isEmpty()==false){
            /*Atualiza os Dados na tabela "Professor".*/
            Conexao.Atualiza_Dados_Professor_MySQL(T_Nome.getText(), T_Data_Nascimento.getText(), T_CPF.getText(), T_Telefone.getText(),
                                                                T_Data_Admissao.getText(), Double.parseDouble(T_Salario_Bruto.getText()));
            /*Limpa os Campos.*/
            BtnCancelar.doClick();
        }
        else
            JOptionPane.showMessageDialog(null, "Preencha todos os campos!!!", "Alerta", JOptionPane.INFORMATION_MESSAGE);
    }//GEN-LAST:event_BtnSalvarActionPerformed

    private void BtnCancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnCancelarActionPerformed
        /*Habilita os Campos.*/
        BtnSalvar.setEnabled(false);
        Seletor.setEnabled(true);
        T_CPF.setEnabled(true);
        BtnBuscar.setEnabled(true);
        
        /*Limpa os Campos.*/
        T_Nome.setText("");
        T_Data_Nascimento.setText("");
        T_CPF.setText("");
        T_Telefone.setText("");
        T_Matricula.setText("");
        T_Periodo.setText("");
        T_Data_Admissao.setText("");
        T_Salario_Bruto.setText("");
    }//GEN-LAST:event_BtnCancelarActionPerformed

    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed
        /*Chama o Form "Menu" novamente.*/
        new Menu().show();
    }//GEN-LAST:event_formWindowClosed

    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        BtnSalvar.setEnabled(false);
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
            java.util.logging.Logger.getLogger(Alterar_Dados.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Alterar_Dados.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Alterar_Dados.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Alterar_Dados.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Alterar_Dados().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BtnBuscar;
    private javax.swing.JButton BtnCancelar;
    private javax.swing.JButton BtnSalvar;
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
