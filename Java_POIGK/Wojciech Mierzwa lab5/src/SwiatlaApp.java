import com.sun.j3d.utils.geometry.*;
import javax.media.j3d.*;
import javax.swing.*;
import java.awt.*;
import com.sun.j3d.utils.universe.SimpleUniverse;
import javax.media.j3d.Transform3D;
import javax.vecmath.Color3f;
import javax.vecmath.Point3d;
import javax.vecmath.Point3f;
import javax.vecmath.Vector3f;



public class SwiatlaApp extends JFrame{

    SwiatlaApp(){

          super("Grafika 3D");

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);


        GraphicsConfiguration config =
           SimpleUniverse.getPreferredConfiguration();

        Canvas3D canvas3D = new Canvas3D(config);
        canvas3D.setPreferredSize(new Dimension(800,600));

        add(canvas3D);
        pack();
        setVisible(true);
        setLocationRelativeTo(null);

        BranchGroup scena = utworzScene();
	    scena.compile();

        SimpleUniverse simpleU = new SimpleUniverse(canvas3D);

        Transform3D przesuniecie_obserwatora = new Transform3D();
        przesuniecie_obserwatora.set(new Vector3f(0.0f,0.0f,4.0f));

        simpleU.getViewingPlatform().getViewPlatformTransform().setTransform(przesuniecie_obserwatora);

        simpleU.addBranchGraph(scena);
    }

    BranchGroup utworzScene(){

         BranchGroup wezel_scena = new BranchGroup();

         Color3f kolor_swiatla_tla      = new Color3f(0.0f, 0.0f, 0.0f);
         Color3f kolor_swiatla_kier     = new Color3f(1.0f, 0.0f, 0.0f);
         Color3f kolor_swiatla_pnkt     = new Color3f(1.0f, 1.0f, 1.0f);
       
         
         TransformGroup obrot_animacja = new TransformGroup();
         obrot_animacja.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
         wezel_scena.addChild(obrot_animacja);
         Alpha alpha_animacja = new Alpha(-1,5000);
         
         RotationInterpolator obracacz = new RotationInterpolator(alpha_animacja, obrot_animacja);
         
         BoundingSphere obszar_ogr =  new BoundingSphere(new Point3d(0.0d,0.0d,0.0d), 10.0d);
         obracacz.setSchedulingBounds(obszar_ogr);
         obrot_animacja.addChild(obracacz);
         
         Vector3f kierunek_swiatla_kier = new Vector3f(4.0f, -5.0f, -1.0f);
         Vector3f kierunek_swiatla_sto  = new Vector3f(5.0f, -5.0f, -1.0f);
                 
         Material material_kuli = new Material(new Color3f(139f/255f,69f/255f,19f/255f), new Color3f(76f/255f,21f/255f,0f/255f),
                 new Color3f(102f/255f,29f/255f,0f/255f), new Color3f(0.0f, 0.0f, 0.0f), 50.0f);


         
         

         ColoringAttributes cattr = new ColoringAttributes();
         cattr.setShadeModel(ColoringAttributes.SHADE_GOURAUD);

         Appearance wyglad_kuli = new Appearance();
       

         wyglad_kuli.setMaterial(material_kuli);
         wyglad_kuli.setColoringAttributes(cattr);
        
         
         AmbientLight swiatlo1= new AmbientLight();
         swiatlo1.setEnable(true);
         swiatlo1.setColor(new Color3f( 1.0f, 1.0f, 1.0f ));
         DirectionalLight swiatlo2= new DirectionalLight();
         swiatlo2.setEnable(true); swiatlo2.setColor(new Color3f( 1.0f, 1.0f, 1.0f ));
         swiatlo2.setDirection(new Vector3f( 1.0f, 0.0f, 0.0f ));
         PointLight swiatlo3= new PointLight( );
         swiatlo3.setEnable(true);
         swiatlo3.setColor(new Color3f( 1.0f, 1.0f, 1.0f ));
         swiatlo3.setPosition(new Point3f( 0.0f, 1.0f, 0.0f ));
         swiatlo3.setAttenuation(new Point3f( 1.0f, 0.0f, 0.0f ));
         SpotLight swiatlo4= new SpotLight( );
         swiatlo4.setEnable(true); swiatlo4.setColor(new Color3f( 1.0f, 1.0f, 1.0f ));
         swiatlo4.setPosition(new Point3f( 0.0f, 1.0f, 0.0f ));
         swiatlo4.setAttenuation(new Point3f( 1.0f, 0.0f, 0.0f ));
         swiatlo4.setDirection(new Vector3f( 1.0f, 0.0f, 0.0f ));
         swiatlo4.setSpreadAngle( 0.785f ); 
         swiatlo4.setConcentration( 0.0f );




         AmbientLight swiatlo_tla = new AmbientLight(kolor_swiatla_tla);
         DirectionalLight swiatlo_kier = new DirectionalLight(kolor_swiatla_kier, kierunek_swiatla_kier);
         PointLight swiatlo_pnkt = new PointLight(kolor_swiatla_pnkt, new Point3f(-0.5f,0.3f,0.2f), new Point3f(0.1f,0.1f,0.1f));
         SpotLight swiatlo_sto = new SpotLight(new Color3f(0.1f, 1.5f, 0.1f), new Point3f(2.5f, 2.9f, 0.5f), new Point3f(0.01f,0.01f,0.01f), kierunek_swiatla_sto, (float)(Math.PI) , 20f);
                                  
         swiatlo_tla.setInfluencingBounds(obszar_ogr);
         swiatlo_kier.setInfluencingBounds(obszar_ogr);
         swiatlo_pnkt.setInfluencingBounds(obszar_ogr);
         swiatlo_sto.setInfluencingBounds(obszar_ogr);

         

         Sphere kula = new Sphere(0.6f,Sphere.GENERATE_NORMALS,100,wyglad_kuli);
         TransformGroup trans_kuli = new TransformGroup();
         Transform3D przesuniecie_kuli = new Transform3D();     
         
         Transform3D przesuniecie_swiatla = new Transform3D();
         przesuniecie_swiatla.set(new Vector3f(0.5f, 0.6f, 0.5f));
         Transform3D  tmp_rot      = new Transform3D();
         tmp_rot.rotZ(Math.PI/2);
         przesuniecie_swiatla.mul(tmp_rot);
         
         TransformGroup transformacja_c = new TransformGroup(przesuniecie_swiatla);
         transformacja_c.addChild(swiatlo_pnkt);
         obrot_animacja.addChild(transformacja_c);
         

         

         przesuniecie_kuli.set(new Vector3f(0.0f, 0.0f,0.0f));
         trans_kuli.setTransform(przesuniecie_kuli);


        wezel_scena.addChild(trans_kuli);
        wezel_scena.addChild(swiatlo_tla);
 
        wezel_scena.addChild(swiatlo_sto);
        trans_kuli.addChild(kula);

       
    
         return wezel_scena;

    }

     public static void main(String args[]){
      new SwiatlaApp();

   }

}
