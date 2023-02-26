package grafika2dksztalty;

import java.awt.*;
import java.awt.geom.*;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;

public class CRamka extends JFrame{
    
    public CRamka()
    {
        super("Grafika 2D - kształty");
        setBounds(50,50,800,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container con = this.getContentPane();
        CObrazek obrazek = new CObrazek();
        con.add(obrazek);

        setVisible(true);
    }

    public static void main(String args[]){
        new CRamka();
    }

}

class CObrazek extends Canvas{
    public void paint(Graphics g){
    	
    	String path = "lab01-grafika2D\\flag.png";
    	BufferedImage img = null;
    	try {
    		
    		img = ImageIO.read(new File(path));
//    		Image image = new Image
    		
    	}
    	catch(IOException e) {
    		e.printStackTrace();
    	}
    	
    	
        Graphics2D g2D = (Graphics2D)g;
        int i;
       

        g2D.setRenderingHint(RenderingHints.KEY_ANTIALIASING,RenderingHints.VALUE_ANTIALIAS_ON);

        GradientPaint niebo = new GradientPaint(0,0,Color.WHITE,0, 200,Color.BLUE);
        g2D.setPaint(niebo);
        g2D.fillRect(0, 0, 800, 600);

        Color myNewColor = new Color (141, 238, 0); 
      
        g2D.setColor(myNewColor);
        g2D.fillRect(0, 400, 800, 600);

        GradientPaint woda = new GradientPaint(400,450,Color.BLUE,650,450,Color.LIGHT_GRAY);
        g2D.setPaint(woda);
        g2D.fill(new Ellipse2D.Float(400,420,400,100));
        
        GradientPaint wyspa = new GradientPaint(430,450,Color.YELLOW,0, 200,Color.BLUE);
        g2D.setPaint(wyspa);
        g2D.fillRect(460, 450, 130, 5);
        
        Color BRAZ = new Color (179, 85, 0); 
        GradientPaint pien = new GradientPaint(430,450,BRAZ,0, 200,Color.BLUE);
        g2D.setPaint(pien);
        g2D.fillRect(480, 360, 10, 90);
        
        GradientPaint liscie = new GradientPaint(400,450,Color.GREEN,650,450,Color.LIGHT_GRAY);
        g2D.setPaint(liscie);
        g2D.fill(new Ellipse2D.Float(455,300,60,60));
        
        GradientPaint statek1 = new GradientPaint(500,450,Color.RED,0, 200,Color.BLUE);
        g2D.setPaint(statek1);
        g2D.fillRect(590, 430, 120, 20);
        
        GradientPaint statek2 = new GradientPaint(500,450,Color.BLACK,0, 200,Color.BLUE);
        g2D.setPaint(statek2);
        g2D.fillRect(590, 420, 120, 20);
        
        
        GradientPaint statek3 = new GradientPaint(500,450,Color.BLACK,0, 200,Color.BLUE);
        g2D.setPaint(statek3);
        g2D.fillRect(620, 400, 15, 30);
        
        GradientPaint maszt = new GradientPaint(500,450,Color.BLACK,0, 200,Color.BLUE);
        g2D.setPaint(maszt);
        g2D.fillRect(680, 400, 3, 30);
        
        Font font = new Font("Arial", Font.BOLD, 11);
        g2D.setFont(font);
        FontMetrics fm = g2D.getFontMetrics();
        g2D.setColor(Color.WHITE);
        g2D.drawString("Polska 1", 660, 430);
        
        


        


        BasicStroke plot = new BasicStroke(10,BasicStroke.CAP_ROUND,
                     BasicStroke.JOIN_ROUND, 0, new float[]{20,10,5,2}, 0);
        g2D.setColor(Color.black);
        g2D.setStroke(plot);
        for( i=0; i < 20; i++)
            g2D.drawLine(10+i*15, 470, 10+i*15, 380);

        g2D.setColor(Color.DARK_GRAY);
        g2D.fill(new Rectangle2D.Float(25,400,250,150));

        g2D.setColor(Color.RED);
        int x2Points[] = {30, 120, 300, 10};
        int y2Points[] = {280, 280,400 , 400};
        GeneralPath polyline =
            new GeneralPath(GeneralPath.WIND_EVEN_ODD, x2Points.length);
        polyline.moveTo (x2Points[0], y2Points[0]);
        
    

        for (int index = 1; index < x2Points.length; index++) {
                polyline.lineTo(x2Points[index], y2Points[index]);
         }
         g2D.fill(polyline);

        g2D.setColor(Color.DARK_GRAY);
        g2D.fill(new Rectangle2D.Float(220,280,20,100));
        g2D.setColor(Color.WHITE);
        g2D.setStroke(new BasicStroke(2.0f));
        for(i = 0; i <30;i+=2)
             g2D.draw(new Ellipse2D.Float(225+i,270-i*2,2*i,2*i));
 
        g2D.setColor(Color.YELLOW);
        g2D.fill(new Ellipse2D.Float(550,0.0f,300,300));
        g2D.setStroke(new BasicStroke(1.0f, BasicStroke.CAP_ROUND,
                     BasicStroke.JOIN_ROUND, 0, new float[]{50,100,50,100}, 0));
        for( i=0; i < 50 ; i++)
            g2D.draw(new Ellipse2D.Float(550-i*5,-i*5,300+i*10,300+i*10));
        
 

        
        Graphics2D g2d = (Graphics2D)g.create();
 
        	
        
        final double rads = Math.toRadians(45);
        final double sin = Math.abs(Math.sin(rads));
        final double cos = Math.abs(Math.cos(rads));
        final int w = (int) Math.floor(img.getWidth() * cos + img.getHeight() * sin);
        final int h = (int) Math.floor(img.getHeight() * cos + img.getWidth() * sin);
        final BufferedImage rotatedImage = new BufferedImage(w, h, img.getType());
        final AffineTransform at = new AffineTransform();
        at.translate(w / 2, h / 2);
        at.rotate(rads,0, 0);
        at.translate(-img.getWidth() / 2, -img.getHeight() / 2);
        final AffineTransformOp rotateOp = new AffineTransformOp(at, AffineTransformOp.TYPE_BILINEAR);
        rotateOp.filter(img,rotatedImage);
        
        g2D.drawImage(rotatedImage, 680, 390, null);
    }
    
    
}

