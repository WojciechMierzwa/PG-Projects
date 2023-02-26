import com.sun.j3d.utils.behaviors.mouse.MouseRotate;
import com.sun.j3d.utils.behaviors.mouse.MouseTranslate;
import com.sun.j3d.utils.behaviors.mouse.MouseZoom;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.geometry.Box;
import com.sun.j3d.utils.image.TextureLoader;
import javax.media.j3d.*;
import javax.swing.*;
import java.awt.*;
import com.sun.j3d.utils.universe.SimpleUniverse;
import javax.media.j3d.Transform3D;
import javax.vecmath.Color3f;
import javax.vecmath.Point2f;
import javax.vecmath.Point3f;
import javax.vecmath.Vector3f;

public class TeksturyApp extends JFrame{

    TeksturyApp(){
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

        BranchGroup scena = utworzScene();
	    scena.compile();

        SimpleUniverse simpleU = new SimpleUniverse(canvas3D);

        Transform3D przesuniecie_obserwatora = new Transform3D();
        Transform3D rot_obs = new Transform3D();
        rot_obs.rotY((float)(-Math.PI/7));
        przesuniecie_obserwatora.set(new Vector3f(-1.2f,1.5f,2.0f));
        przesuniecie_obserwatora.mul(rot_obs);
        rot_obs.rotX((float)(-Math.PI/6));
        przesuniecie_obserwatora.mul(rot_obs);

        simpleU.getViewingPlatform().getViewPlatformTransform().setTransform(przesuniecie_obserwatora);

        simpleU.addBranchGraph(scena);

    }

    BranchGroup utworzScene()
    {

        int i;

        
        BranchGroup wezel_scena = new BranchGroup();

        Appearance wyglad_ziemia = new Appearance();
        Appearance wyglad_mury   = new Appearance();
        Appearance wyglad_daszek = new Appearance();
        Appearance wyglad_sciana   = new Appearance();
        

       
        
        
        
        //

        TextureLoader loader = new TextureLoader("obrazki/trawka.gif",null);
        ImageComponent2D image = loader.getImage();
        
        Texture Tekstura = new TextureLoader("obrazki/clouds.gif", null, new Container()).getTexture();


        Texture2D trawka = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
                                        image.getWidth(), image.getHeight());

        trawka.setImage(0, image);
        trawka.setBoundaryModeS(Texture.WRAP);
        trawka.setBoundaryModeT(Texture.WRAP);


        loader = new TextureLoader("obrazki/murek.jpg",this);
        image = loader.getImage();

        Texture2D murek = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
                                        image.getWidth(), image.getHeight());
        
        murek.setImage(0, image);
        murek.setBoundaryModeS(Texture.WRAP);
        murek.setBoundaryModeT(Texture.WRAP);
        
        loader = new TextureLoader("obrazki/plytki.jpg",this);
        image = loader.getImage();
        
        Texture2D plytki = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
                image.getWidth(), image.getHeight());

        plytki.setImage(0, image);
        plytki.setBoundaryModeS(Texture.WRAP);
        plytki.setBoundaryModeT(Texture.WRAP);

        loader = new TextureLoader("obrazki/drewno.jpg",this);
        image = loader.getImage();
        
        //
        Texture2D sciana = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
                image.getWidth(), image.getHeight());

        sciana.setImage(0, image);
        sciana.setBoundaryModeS(Texture.WRAP);
        sciana.setBoundaryModeT(Texture.WRAP);
        
        
        TransformGroup Myszka = new TransformGroup();
        Myszka.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        wezel_scena.addChild(Myszka);


        BoundingSphere bounds = new BoundingSphere();
        AmbientLight lightA = new AmbientLight();
        lightA.setInfluencingBounds(bounds);
        Myszka.addChild(lightA);

        DirectionalLight lightD = new DirectionalLight();
        lightD.setInfluencingBounds(bounds);
        lightD.setDirection(new Vector3f(0.0f, 0.0f, -1.0f));
        lightD.setColor(new Color3f(1.0f, 1.0f, 1.0f));
        Myszka.addChild(lightD);


        wyglad_ziemia.setTexture(trawka);
        wyglad_mury.setTexture(murek);
        wyglad_sciana.setTexture(sciana);
        wyglad_daszek.setTexture(plytki);

        Point3f[]  coords = new Point3f[4];
        for(i = 0; i< 4; i++)
            coords[i] = new Point3f();

        Point2f[]  tex_coords = new Point2f[4];
        for(i = 0; i< 4; i++)
            tex_coords[i] = new Point2f();

        coords[0].y = 0.0f;
        coords[1].y = 0.0f;
        coords[2].y = 0.0f;
        coords[3].y = 0.0f;

        coords[0].x = 0.5f;
        coords[1].x = 0.5f;
        coords[2].x = -0.5f;
        coords[3].x = -0.5f;

        coords[0].z = 0.5f;
        coords[1].z = -0.5f;
        coords[2].z = -0.5f;
        coords[3].z = 0.5f;

        tex_coords[0].x = 0.0f;
        tex_coords[0].y = 0.0f;

        tex_coords[1].x = 10.0f;
        tex_coords[1].y = 0.0f;

        tex_coords[2].x = 0.0f;
        tex_coords[2].y = 10.0f;

        tex_coords[3].x = 10.0f;
        tex_coords[3].y = 10.0f;
        
        
        
        Appearance Wyglad = new Appearance();
        Wyglad.setTexture(Tekstura);
        Wyglad.setTextureAttributes(new TextureAttributes());
        
        Sphere Sfera = new Sphere(6.5f, 
        		 Primitive.GENERATE_NORMALS_INWARD + Primitive.GENERATE_TEXTURE_COORDS, 
        		 Wyglad);
        
        
        Myszka.addChild(Sfera);


        //ziemia

        QuadArray qa_ziemia = new QuadArray(4, GeometryArray.COORDINATES|
                GeometryArray.TEXTURE_COORDINATE_2);
        qa_ziemia.setCoordinates(0,coords);

        qa_ziemia.setTextureCoordinates(0, tex_coords);


        
        Shape3D ziemia = new Shape3D(qa_ziemia);
        ziemia.setAppearance(wyglad_ziemia);

        Myszka.addChild(ziemia);
        
        
        Point3f[]  coords1 = new Point3f[4];
        for(i = 0; i< 4; i++)
            coords1[i] = new Point3f();

        Point2f[]  tex_coords1 = new Point2f[4];
        for(i = 0; i< 4; i++)
            tex_coords1[i] = new Point2f();

        coords1[0].y = 0.0f;
        coords1[1].y = 0.0f;
        coords1[2].y = 0.0f;
        coords1[3].y = 0.0f;

        coords1[0].x = 0.5f;
        coords1[1].x = 0.5f;
        coords1[2].x = -0.5f;
        coords1[3].x = -0.5f;

        coords1[0].z = -0.5f;
        coords1[1].z = 0.5f;
        coords1[2].z = 0.5f;
        coords1[3].z = -0.5f;

        tex_coords1[0].x = 0.0f;
        tex_coords1[0].y = 0.0f;

        tex_coords1[1].x = 10.0f;
        tex_coords1[1].y = 0.0f;

        tex_coords1[2].x = 0.0f;
        tex_coords1[2].y = 10.0f;

        tex_coords1[3].x = 10.0f;
        tex_coords1[3].y = 10.0f;
        
        QuadArray qa_ziemia2 = new QuadArray(4, GeometryArray.COORDINATES|
                GeometryArray.TEXTURE_COORDINATE_2);
        qa_ziemia2.setCoordinates(0,coords1);

        qa_ziemia2.setTextureCoordinates(0, tex_coords1);
        
        
        

        Shape3D ziemia2 = new Shape3D(qa_ziemia2);
        ziemia2.setAppearance(wyglad_ziemia);

        Myszka.addChild(ziemia2);


        //wieza
        

        TransformGroup wieza_p = new TransformGroup();
        Transform3D przesuniecie_wiezy = new Transform3D();
        przesuniecie_wiezy.set(new Vector3f(0.0f,0.3f,0.0f));
        wieza_p.setTransform(przesuniecie_wiezy);

        Cylinder walec = new Cylinder(0.2f,0.6f,Cylinder.GENERATE_NORMALS| Cylinder.GENERATE_TEXTURE_COORDS, wyglad_sciana);
        
      

        wieza_p.addChild(walec);
        Myszka.addChild(wieza_p);
       
      


        TransformGroup daszek_p = new TransformGroup();
        Transform3D przesuniecie_daszka = new Transform3D();
        przesuniecie_daszka.set(new Vector3f(0.0f,0.7f,0.0f));
        daszek_p.setTransform(przesuniecie_daszka);

        Cone daszek = new Cone(0.25f,0.2f,Cone.GENERATE_NORMALS|Cone.GENERATE_TEXTURE_COORDS,wyglad_daszek);

        daszek_p.addChild(daszek);
        Myszka.addChild(daszek_p);
        
        TransformGroup murek_p1 = new TransformGroup();
        Transform3D przesuniecie_murku = new Transform3D();
        przesuniecie_murku.set(new Vector3f(-0.4f,0.0f,0.0f));
        murek_p1.setTransform(przesuniecie_murku);

        Box murek1 = new Box(0.1f, 0.1f, 0.5f,
        		 Box.GENERATE_TEXTURE_COORDS, 
        		 wyglad_mury);

        murek_p1.addChild(murek1);
        Myszka.addChild(murek_p1);

        TransformGroup murek_p2 = new TransformGroup();
        Transform3D przesuniecie_murku2 = new Transform3D();
        przesuniecie_murku2.set(new Vector3f(0.4f,0.0f,0.0f));
        murek_p2.setTransform(przesuniecie_murku2);

        Box murek2 = new Box(0.1f, 0.1f, 0.5f,
        		 Box.GENERATE_TEXTURE_COORDS, 
        		 wyglad_mury);

        murek_p2.addChild(murek2);
        Myszka.addChild(murek_p2);
        
        TransformGroup murek_p3 = new TransformGroup();
        Transform3D przesuniecie_murku3 = new Transform3D();
        przesuniecie_murku3.set(new Vector3f(0.0f,0.0f,0.4f));
        murek_p3.setTransform(przesuniecie_murku3);

        Box murek3 = new Box(0.5f, 0.1f, 0.1f,
        		 Box.GENERATE_TEXTURE_COORDS, 
        		 wyglad_mury);

        murek_p3.addChild(murek3);
        Myszka.addChild(murek_p3);
        
        
        TransformGroup murek_p4 = new TransformGroup();
        Transform3D przesuniecie_murku4 = new Transform3D();
        przesuniecie_murku4.set(new Vector3f(0.0f,0.0f,-0.4f));
        murek_p4.setTransform(przesuniecie_murku4);

        Box murek4 = new Box(0.5f, 0.1f, 0.1f,
        		 Box.GENERATE_TEXTURE_COORDS, 
        		 wyglad_mury);

        murek_p4.addChild(murek4);
        Myszka.addChild(murek_p4);
        
        MouseRotate myszObrot = new MouseRotate(Myszka);
        myszObrot.setSchedulingBounds(bounds);
        Myszka.addChild(myszObrot);
        
        MouseTranslate przesMysza = new MouseTranslate(Myszka);
        przesMysza.setSchedulingBounds(bounds);
        Myszka.addChild(przesMysza);
        
        MouseZoom myszZoom = new MouseZoom(Myszka);
        myszZoom.setSchedulingBounds(bounds);
        Myszka.addChild(myszZoom);



        return wezel_scena;


    }

    public static void main(String args[]){
      new TeksturyApp();

   }

}
