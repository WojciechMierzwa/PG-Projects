import java.awt.*;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferStrategy;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class Sterowanie extends JFrame{
    
    private Image       tlo1;
    private Image       sterowiec;
    private Image       obiekt;
    private boolean     klawisze[];
    private int         wsp[];
    private Timer       zegar;
    int check1=1;
    int check2=1;
  

    class Zadanie extends TimerTask{

        public void run()
        {

            if(klawisze[0])
                wsp[1]-=1;
            if(klawisze[1])
                wsp[1]+=1;

            if(klawisze[2])
                wsp[0]-=1;
            if(klawisze[3])
                wsp[0]+=1;

           wsp[0] = (wsp[0]<0)?0:wsp[0];
           wsp[0] = (wsp[0]>720)?720:wsp[0];
           wsp[1] = (wsp[1]<20)?20:wsp[1];
           wsp[1] = (wsp[1]>540)?540:wsp[1];
            repaint();
        }
  }
    Timer czas1 = new Timer(); //tworzymy Timera
    TimerTask czasZad1 = new TimerTask(){
    public void run(){
    	sterowiec       = new ImageIcon("obrazki/sterowiec.png").getImage();
    }
    };
    Timer czas2 = new Timer(); //tworzymy Timera
    TimerTask czasZad2 = new TimerTask(){
    public void run(){
    	sterowiec       = new ImageIcon("obrazki/sterowiec2.png").getImage();
    }
    };
    
    public void pause() {
        this.czas1.cancel();
        this.czas2.cancel();
    }
    
    
    public void resume() {
        this.czas1 = new Timer();
        this.czas1.schedule( czasZad1, 0, 299 );
        this.czas2 = new Timer();
        this.czas2.schedule( czasZad2, 300, 599 );
    }

    Sterowanie(){
        super("Grafika 2D - sterowanie");
        setBounds(50,50,800,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setVisible(true);
        createBufferStrategy(2);

        czas1.schedule(czasZad1, 0, 299);
        czas2.schedule(czasZad2, 300, 599);
        klawisze        = new boolean[4];
        wsp             = new int[2];
        tlo1            = new ImageIcon("obrazki/tlo1.jpg").getImage();
        sterowiec       = new ImageIcon("obrazki/sterowiec.png").getImage();
        Shape r1 = new Rectangle(wsp[1]+5,wsp[1],wsp[0]+5,wsp[0]);
        if(wsp[0]==700)
        {
        	
        }
        
        	
     

        wsp[0] = 20;
        wsp[1] = 40;
        
        

        zegar = new Timer();
        zegar.scheduleAtFixedRate(new Zadanie(),0,20);

        this.addKeyListener(new KeyListener(){

            public void keyPressed(KeyEvent e){
                switch(e.getKeyCode()){
                    case KeyEvent.VK_UP:      klawisze[0] = true; break;
                    case KeyEvent.VK_DOWN:    klawisze[1] = true; break;
                    case KeyEvent.VK_LEFT:    klawisze[2] = true; break;
                    case KeyEvent.VK_RIGHT:   klawisze[3] = true; break;
                    case KeyEvent.VK_SPACE:    
                    	if(check1%5==1)
                    	{
                    		tlo1            = new ImageIcon("obrazki/tlo2.jpg").getImage();
                    		check1=2;
                    	}
                    	if(check1%5==3)
                    	{
                    		tlo1            = new ImageIcon("obrazki/tlo1.jpg").getImage();
                    		check1=4;
                    	}
                    	
                    	break;
                    case KeyEvent.VK_ENTER:
                    	if(check2%5==1)
                    	{
                    		pause();
                    		sterowiec       = new ImageIcon("obrazki/balon.png").getImage();
                    		check2=2;
                    	}
                    	if(check2%5==3)
                    	{
                    		sterowiec       = new ImageIcon("obrazki/sterowiec.png").getImage();
                    		resume();
                    		check2=4;
                    	}
                    	break;
                }
            }

            public void keyReleased(KeyEvent e){
                switch(e.getKeyCode()){
                    case KeyEvent.VK_UP:      klawisze[0] = false; break;
                    case KeyEvent.VK_DOWN:    klawisze[1] = false; break;
                    case KeyEvent.VK_LEFT:    klawisze[2] = false; break;
                    case KeyEvent.VK_RIGHT:   klawisze[3] = false; break;
                    case KeyEvent.VK_SPACE: 
                    	if(check1%5==2)
                    	{
                    		check1=3;
                    	}
                    	if(check1%5==4)
                    	{
                    		check1=1;
                    	}
                    	break;
                    case KeyEvent.VK_ENTER: 
                    	if(check2%5==2)
                    	{
                    		check2=3;
                    	}
                    	if(check2%5==4)
                    	{
                    		check2=1;
                    	}
                    	break;
                }
            }

            public void keyTyped(KeyEvent e){
            }
        }
    );
  }
    
    public static void main(String[] args)
    {
        Sterowanie okno = new Sterowanie();
        okno.repaint();
       
    }
    
    public void paint(Graphics g)
    {
      
        BufferStrategy bstrategy = this.getBufferStrategy();
        Graphics2D g2d = (Graphics2D)bstrategy.getDrawGraphics();

        g2d.drawImage(tlo1, 0,0,null);
        g2d.drawImage(sterowiec,wsp[0],wsp[1],null);
        g2d.setColor(Color.DARK_GRAY);
        g2d.setFont(new Font("Arial",Font.BOLD,20));
        if(wsp[1]==20 || wsp[1]==540)
        {
        	 g2d.drawString("Kolizja " ,300, 300);
        }
        g2d.drawString("Wsp x: " + wsp[0], 5, 55);
        
        g2d.drawString("Wsp y: "+ wsp[1], 5, 100);
        g2d.dispose();

        bstrategy.show();
        
    }
}


