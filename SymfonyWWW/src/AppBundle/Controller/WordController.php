<?php

namespace AppBundle\Controller;

use AppBundle\Entity\Word;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;

/**
 * Controller used to manage Words collection in the public part of the site.
 *
 * @Route("/collect")
 *
 * @author Paul-Axel MARIE
 */
class WordController extends Controller
{
    /**
     * @Route("/", defaults={"_format"="html"}, name="central_index")
     * @Method("GET")
     * @Cache(smaxage="10")
     */
    public function indexAction($_format)
    {
        //$entities = $this->getDoctrine()->getRepository(Post::class)->findLatest($page);
        $entities = false;
        return $this->render('central/index.'.$_format.'.twig', ['$entities' => $entities]);
    }
}