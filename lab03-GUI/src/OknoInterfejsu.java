import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.*;


public class OknoInterfejsu extends JFrame{
    

   private JButton przyciski[];
   private JTextArea oknoTekstowe;
   private JComboBox wybor;
   private String wybor_str[];
   int check=0;
   String function = ""; 
   double[] temporary = {0, 0};
   double result;

   private class ObslugaPrzycisku implements ActionListener{

       private JFrame ref_okno;

       ObslugaPrzycisku(JFrame okno){
            ref_okno = okno;
       }
       
       public void getResult() {
           double result = 0;
           temporary[1] = Double.parseDouble(oknoTekstowe.getText());

           String temp0 = Double.toString(temporary[0]);
           String temp1 = Double.toString(temporary[1]);
           try {
               if(temp0.contains("-")) {
                   String[] temp00 = temp0.split("-", 2);
                   temporary[0] = (Double.parseDouble(temp00[1]) * -1);
               }
               if(temp1.contains("-")) {
                   String[] temp11 = temp1.split("-", 2);
                   temporary[1] = (Double.parseDouble(temp11[1]) * -1);
               }
           } catch( ArrayIndexOutOfBoundsException e ){
               clear();
               oknoTekstowe.setText("Error");
           }

           /*order is Parenthsis, Exponent, Mul, Div, Add, Sub*/
           try{
               
               if( function.equals("*") )
                   result = temporary[0] * temporary[1];
               else if( function.equals("/") )
                   result = temporary[0] / temporary[1];
               else if( function.equals("%") )
                   result = temporary[0] % temporary[1];
               else if( function.equals("+") )
                   result = temporary[0] + temporary[1];
               else if( function.equals("-") )
                   result = temporary[0] - temporary[1];

               oknoTekstowe.setText(Double.toString(result));
           } catch( Exception e ){
               clear();
               oknoTekstowe.setText("Error");
           }
       }
       public void clear(){
           try{
               oknoTekstowe.setText(""); /*clears display*/
               function = null;
               for( int i=0; i < temporary.length; ++i ){
                   temporary[i] = 0;    /*sets operand vars to 0*/
               }
           } catch(NullPointerException e) {
               clear();
               oknoTekstowe.setText("Error");
           }
       }

      

       public void actionPerformed(ActionEvent e) {
           JButton bt = (JButton)e.getSource();
           if(bt==przyciski[0])
           	oknoTekstowe.append("0");
           else if(bt==przyciski[1])
           	oknoTekstowe.append("1");
           else if(bt==przyciski[2])
                oknoTekstowe.append("2");
           else if(bt==przyciski[3])
           	oknoTekstowe.append("3");
           else if(bt==przyciski[4])
           	oknoTekstowe.append("4");
           else if(bt==przyciski[5])
           	oknoTekstowe.append("5");
           else if(bt==przyciski[6])
           	oknoTekstowe.append("6");
           else if(bt==przyciski[7])
           	oknoTekstowe.append("7");
           else if(bt==przyciski[8])
           	oknoTekstowe.append("8");
           else if(bt==przyciski[9])
           	oknoTekstowe.append("9");
           else if(bt==przyciski[10])
           {
        	   temporary[0] = Double.parseDouble(oknoTekstowe.getText());
               function = "+";
               oknoTekstowe.setText("");
           }
           else if(bt==przyciski[11])
           {
        	   temporary[0] = Double.parseDouble(oknoTekstowe.getText());
               function = "-";
               oknoTekstowe.setText("");
           }
           else if(bt==przyciski[12])
           {
        	   temporary[0] = Double.parseDouble(oknoTekstowe.getText());
               function = "/";
               oknoTekstowe.setText("");
           }
           else if(bt==przyciski[13])
           {
        	   temporary[0] = Double.parseDouble(oknoTekstowe.getText());
               function = "*";
               oknoTekstowe.setText("");
           }
           	
           else if(bt==przyciski[14])
        	   clear();
           	
           else if(bt==przyciski[15])
           {
        	   getResult();
           }
           	
       }

  }

   private class ObslugaListy implements ActionListener{

        public void actionPerformed(ActionEvent e) {
              JComboBox cb = (JComboBox)e.getSource();
            String tmp = (String)cb.getSelectedItem();

          if(tmp.equals(wybor_str[0]))
            oknoTekstowe.append("Wybór opcji 1\n");
          else if (tmp.equals(wybor_str[1]))
              oknoTekstowe.append("Wybór opcji 2\n");
          else if (tmp.equals(wybor_str[2]))
              oknoTekstowe.append("Wybór opcji 3\n");           
        }
 }



   public OknoInterfejsu()
   {
        super("Okno interfejsu");
        setSize(400,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       
       //-------------------------------------------------------
        przyciski = new JButton[16];
        przyciski[0] = new JButton("0");
        przyciski[0].addActionListener(new ObslugaPrzycisku(this));

        przyciski[1] = new JButton("1");
        przyciski[1].addActionListener(new ObslugaPrzycisku(this));

        przyciski[2] = new JButton("2");
        przyciski[2].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[3] = new JButton("3");
        przyciski[3].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[4] = new JButton("4");
        przyciski[4].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[5] = new JButton("5");
        przyciski[5].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[6] = new JButton("6");
        przyciski[6].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[7] = new JButton("7");
        przyciski[7].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[8] = new JButton("8");
        przyciski[8].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[9] = new JButton("9");
        przyciski[9].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[10] = new JButton("+");
        przyciski[10].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[11] = new JButton("-");
        przyciski[11].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[12] = new JButton("/");
        przyciski[12].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[13] = new JButton("*");
        przyciski[13].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[14] = new JButton("c");
        przyciski[14].addActionListener(new ObslugaPrzycisku(this));
        
        przyciski[15] = new JButton("=");
        przyciski[15].addActionListener(new ObslugaPrzycisku(this));

        JPanel panelPrzyciski   = new JPanel(new GridLayout(4,5));
        panelPrzyciski.add(przyciski[0]);
        panelPrzyciski.add(przyciski[1]);
        panelPrzyciski.add(przyciski[2]);
        panelPrzyciski.add(przyciski[3]);
        panelPrzyciski.add(przyciski[4]);
        panelPrzyciski.add(przyciski[5]);
        panelPrzyciski.add(przyciski[6]);
        panelPrzyciski.add(przyciski[7]);
        panelPrzyciski.add(przyciski[8]);
        panelPrzyciski.add(przyciski[9]);
        panelPrzyciski.add(przyciski[10]);
        panelPrzyciski.add(przyciski[11]);
        panelPrzyciski.add(przyciski[12]);
        panelPrzyciski.add(przyciski[13]);
        panelPrzyciski.add(przyciski[14]);
        panelPrzyciski.add(przyciski[15]);


        //-------------------------------------------------------
        oknoTekstowe = new JTextArea(" ");

        //-------------------------------------------------------
        JPanel gornyPasek  = new JPanel(new FlowLayout());

        gornyPasek.add(new JLabel("Opcje do wyboru: "));
        wybor_str = new String[]{ 
            "Opcja 1","Opcja 2","Opcja 3" };
        wybor = new JComboBox(wybor_str);
        wybor.addActionListener(new ObslugaListy());
        gornyPasek.add(wybor);

        //-------------------------------------------------------
        Container content       = getContentPane();
        content.setLayout(new BorderLayout());

        content.add(panelPrzyciski,BorderLayout.SOUTH);
        content.add(new JScrollPane(oknoTekstowe),BorderLayout.CENTER);
        content.add(gornyPasek,BorderLayout.NORTH);
        setVisible(true);
   }


   public static void main(String args[]){
       new OknoInterfejsu();
   }

}
